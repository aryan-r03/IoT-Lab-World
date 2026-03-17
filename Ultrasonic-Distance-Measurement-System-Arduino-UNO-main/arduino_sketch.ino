/* 
> For custom audio output 
> Run with ' Distance_custom_audio.py '
*/



#define TRIG 9 // TRIG pin of MQ2 -> D9 of arduino 
#define ECHO 10 // ECHO pin of MQ2 -> D10 of arduino 
#define LED 3 // LED long let -> D3 of arduino 

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo
  long duration = pulseIn(ECHO, HIGH, 30000); // timeout safety
  float distance = duration * 0.0343 / 2;    // centimeters 

  // Debug output
  Serial.println(distance);

  // Range check
  if (distance > 10 && distance < 40) {
    digitalWrite(LED, HIGH);
    Serial.println("PLAY_AUDIO");   // <-- THIS IS CRITICAL
    delay(1500); // debounce so Python doesn't get spammed
  } else {
    digitalWrite(LED, LOW);
  }

  delay(100);
}
