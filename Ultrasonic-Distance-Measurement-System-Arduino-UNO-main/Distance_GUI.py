import serial
import pygame
import subprocess
import time

# ================= SERIAL CONFIG =================
PORT = "/dev/ttyUSB0"   # macOS (often): /dev/tty.usbserial-XXXX
BAUD = 9600

ser = serial.Serial(PORT, BAUD, timeout=1)
time.sleep(2)

# ================= GUI CONFIG =================
pygame.init()
WIDTH, HEIGHT = 600, 300
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Object Distance Monitor")

font_big = pygame.font.SysFont("Arial", 48, bold=True)
font_small = pygame.font.SysFont("Arial", 22)

BLACK = (15, 15, 15)
GREEN = (0, 255, 140)
YELLOW = (255, 200, 0)
RED = (255, 80, 80)

clock = pygame.time.Clock()

display_distance = "--"

# ================= HELPER FUNCTIONS =================
def draw_screen(distance):
    screen.fill(BLACK)

    if distance == "--":
        color = GREEN
        text = "-- cm"
    else:
        if distance < 20:
            color = RED
        elif distance < 50:
            color = YELLOW
        else:
            color = GREEN
        text = f"{distance} cm"

    title = font_small.render("Ultrasonic Distance Sensor", True, color)
    value_text = font_big.render(text, True, color)

    screen.blit(title, (20, 20))
    screen.blit(value_text, (200, 130))
    pygame.display.flip()

def speak_blocking(text):
    subprocess.run(["say", text])  # INTENTIONALLY BLOCKING

# ================= MAIN LOOP =================
running = True
while running:
    clock.tick(30)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # -------- STEP 1: GET DISTANCE --------
    if ser.in_waiting:
        try:
            line = ser.readline().decode().strip()
            distance = round(float(line), 1)

            # -------- STEP 2: DISPLAY --------
            display_distance = distance
            draw_screen(display_distance)

            # -------- STEP 3: SPEAK --------
            speak_blocking(f"Object at {display_distance} centimeters")

            # -------- STEP 4: WAIT FOR NEXT VALUE ----------- (flush old serial data to avoid backlog)
            ser.reset_input_buffer()

        except:
            pass
    else:
        draw_screen(display_distance)

# ================= CLEANUP =================
ser.close()
pygame.quit()
