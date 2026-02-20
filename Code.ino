const int pingPin = 9;

// Motor pins
int in1 = 5;
int in2 = 6;
int in3 = 7;
int in4 = 8;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
}

void loop() {
  long duration, distance;

  // Send ultrasonic pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // Receive echo
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  distance = duration * 0.034 / 2;

  if (distance < 20) {
    // Obstacle detected → Turn
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } 
  else {
    // Move forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }

  delay(100);
}