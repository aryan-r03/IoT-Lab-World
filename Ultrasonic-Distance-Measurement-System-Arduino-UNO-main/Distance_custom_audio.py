import serial
import pygame
import time

SERIAL_PORT = "/dev/cu.usbmodem101" #check your board serial post code , from the IDE 
BAUD = 9600 

# Audio files (WAV or MP3)
AUDIO_1 = "audio_1.mp3"
AUDIO_2 = "audio_2.mp3"
AUDIO_3 = "audio_3.mp3"

# Timing controls (seconds)
DELAY_AUDIO_2 = 1
DELAY_AUDIO_3 = 2
COOLDOWN = 5


pygame.mixer.init()

sound1 = pygame.mixer.Sound(AUDIO_1)
sound2 = pygame.mixer.Sound(AUDIO_2)
sound3 = pygame.mixer.Sound(AUDIO_3)

# Optional volume control (0.0 to 1.0)
sound1.set_volume(1.0)
sound2.set_volume(0.8)
sound3.set_volume(0.9)

last_played = 0

def open_serial():
    while True:
        try:
            return serial.Serial(SERIAL_PORT, BAUD, timeout=1)
        except serial.SerialException:
            print("Waiting for Interference...")
            time.sleep(1)
            time.sleep(2)

ser = open_serial()
print("Listening for triggers...")

while True:
    try:
        line = ser.readline().decode(errors="ignore").strip()

        if line == "PLAY_AUDIO":
            now = time.time()

            if now - last_played > COOLDOWN:
                print("Trigger received → Warning announced ")

                sound1.play()

                time.sleep(DELAY_AUDIO_2)
                sound2.play()

                time.sleep(DELAY_AUDIO_3)
                sound3.play()

                last_played = now

    except serial.SerialException:
        print("Serial disconnected. Reconnecting...")
        ser.close()
        ser = open_serial()
