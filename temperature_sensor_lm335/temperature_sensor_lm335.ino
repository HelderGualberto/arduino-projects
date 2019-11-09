#define ANALOG_IN A0
#define INPUT_VOLTAGE 4.98

void setup(){
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:

  float analog = analogRead(A0);
  float voltage = analog*5000/1023.0; //mV
  float celcius = voltage/10.0; 

  Serial.print("Analog: ");Serial.println(analog);
  Serial.print("Voltage: ");Serial.print(voltage);Serial.println("mV");
  Serial.print("Temperature: ");Serial.print(celcius);Serial.println("°C");
  Serial.println("\n");
  delay(1000);
}
