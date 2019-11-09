#define out 8
void setup() {
  // put your setup code here, to run once:
  pinMode(out, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog = analogRead(A0);
  analogWrite(out, analog/2);
}
