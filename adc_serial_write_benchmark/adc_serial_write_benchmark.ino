#define D13 13

void setup() {
  Serial.begin(2000000);
  pinMode(D13, OUTPUT);
}

int _high = 0;
int _low = 0; 
void loop() {
  // ADC 10 bits 0 - 1024 
  // Voltage ref 0v - 3.3v

  Serial.println(analogRead(A0));

  if(_low > 550){
    digitalWrite(D13, HIGH);
    _low = 0;
  }
  if(_high > 600){
    digitalWrite(D13, LOW);
    _high = 0;
    _low = 0;
  }
  _high+=1;
  _low+=1;
}
