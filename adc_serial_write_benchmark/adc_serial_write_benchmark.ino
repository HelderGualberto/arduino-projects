
void setup() {
  Serial.begin(230400);
  pinMode(A0, INPUT);
}

void loop() {
  // ADC 10 bits 0 - 1024 
  // Voltage ref 0v - 3.3v
  Serial.println(analogRead(A0));
}
