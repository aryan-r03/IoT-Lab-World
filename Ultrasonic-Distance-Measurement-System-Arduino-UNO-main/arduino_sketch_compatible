/*

 > UNIVERSAL ULTRASONIC DISTANCE SENSOR
 > Compatible with both:
    - Distance_custom_audio.py (trigger-based)
    - Distance_GUI.py (continuous distance)
  
 > HOW TO SELECT MODE:
    - For custom audio (trigger mode): Keep pin 2 disconnected (floating)
    - For GUI mode: Connect pin 2 to GND
  
 > OR simply use the default AUTO mode that outputs both!

 */

#define TRIG 9        // TRIG pin of HC-SR04 -> D9 of Arduino 
#define ECHO 10       // ECHO pin of HC-SR04 -> D10 of Arduino 
#define LED 3         // LED long leg -> D3 of Arduino 
#define MODE_PIN 2    // Mode selector pin (optional - connect to GND for GUI mode)

// Distance thresholds for trigger
#define MIN_DISTANCE 10
#define MAX_DISTANCE 40

// Debounce delay to prevent spam
#define DEBOUNCE_DELAY 1500

// Mode selection
enum Mode {
  AUTO,      // Outputs both distance and trigger (works with both scripts)
  TRIGGER,   // Only outputs PLAY_AUDIO when object detected
  GUI        // Only outputs continuous distance values
};

Mode currentMode = AUTO;  // Default mode
unsigned long lastTriggerTime = 0;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(MODE_PIN, INPUT_PULLUP);  // Use internal pullup
  
  digitalWrite(LED, LOW);
  Serial.begin(9600);
  
  // Determine mode based on MODE_PIN
  delay(100);  // Allow pin to stabilize
  
  if (digitalRead(MODE_PIN) == LOW) {
    currentMode = GUI;  // Pin connected to GND = GUI mode only
  } else {
    currentMode = AUTO;  // Default = both outputs
  }
  
  delay(500);  // Startup delay
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo with timeout safety
  long duration = pulseIn(ECHO, HIGH, 30000);
  float distance = duration * 0.0343 / 2;  // Convert to centimeters
  
  // Validate distance reading
  if (distance <= 0 || distance > 400) {
    distance = 0;  // Invalid reading
  }
  
  // Output based on mode
  switch (currentMode) {
    case AUTO:
      // Output distance for GUI
      Serial.println(distance);
      
      // Check if object is in trigger range
      if (distance > MIN_DISTANCE && distance < MAX_DISTANCE) {
        unsigned long currentTime = millis();
        
        // Send trigger if cooldown period has passed
        if (currentTime - lastTriggerTime > DEBOUNCE_DELAY) {
          digitalWrite(LED, HIGH);
          Serial.println("PLAY_AUDIO");
          lastTriggerTime = currentTime;
        }
      } else {
        digitalWrite(LED, LOW);
      }
      
      delay(100);  // Sampling delay
      break;
      
    case TRIGGER:
      // Only output trigger when object detected
      if (distance > MIN_DISTANCE && distance < MAX_DISTANCE) {
        unsigned long currentTime = millis();
        
        if (currentTime - lastTriggerTime > DEBOUNCE_DELAY) {
          digitalWrite(LED, HIGH);
          Serial.println("PLAY_AUDIO");
          lastTriggerTime = currentTime;
        }
      } else {
        digitalWrite(LED, LOW);
      }
      
      delay(100);
      break;
      
    case GUI:
      // Only output distance continuously
      Serial.println(distance);
      
      // Visual feedback via LED
      if (distance > MIN_DISTANCE && distance < MAX_DISTANCE) {
        digitalWrite(LED, HIGH);
      } else {
        digitalWrite(LED, LOW);
      }
      
      delay(100);
      break;
  }
}
