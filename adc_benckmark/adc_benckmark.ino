void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

int t_start = millis();
int adc_counter = 0;

void loop() {
  int adc = analogRead(A0);
  adc_counter += 1;
  int now = millis();
  if((now - t_start) > 1000){
    t_start = now;
    Serial.println(adc_counter);
    adc_counter = 0;
  }
}
