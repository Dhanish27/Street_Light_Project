#include <Wire.h>
#include <BH1750.h>

#include<SoftwareSerial.h>
SoftwareSerial s(5,6);

BH1750 lightMeter;
int Led1 = 7;

void setup() {
  s.begin(9600);
  pinMode(Led1, OUTPUT);
  Serial.begin(9600);
  Wire.begin(); // Initialize I2C communication
  // Initialize the BH1750 sensor
  lightMeter.begin();
}

void loop() {
  int data1=1;
  int data2=0;
  // Read the intensity of light in lux
  float lux = lightMeter.readLightLevel();
  // Print the intensity of light to the serial monitor
  Serial.print("Light intensity: ");
  Serial.print(lux);
  Serial.println(" lux");
  // Check if lux value is below 50
  if (lux < 50) {
    digitalWrite(Led1, HIGH); // Turn on the LED
      if(s.available()>0){
    s.write(data1); 
  }
  } else {
    digitalWrite(Led1, LOW); // Turn off the LED
    if(s.available()>0){
    s.write(data2); 
  }
  }
  delay(1000); // Wait for a second before reading again
}
