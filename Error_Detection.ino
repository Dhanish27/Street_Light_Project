#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

#include <SoftwareSerial.h>
SoftwareSerial s(D6, D5);

void setup() {
  Wire.begin(D2, D1); // Initialize I2C with SDA on D2 (GPIO4) and SCL on D1 (GPIO5)
  s.begin(9600);
  Serial.begin(9600);

  // Initialize the BH1750 sensor
  lightMeter.begin();
}

void loop() {
  int data;
  if (s.available() > 0) {
    data = s.read();
    Serial.println(data);
  }
  if (data == 1) {
    // Read the intensity of light in lux
    float lux = lightMeter.readLightLevel();

    // Print the intensity of light to the serial monitor
    Serial.print("Light intensity: ");
    Serial.print(lux);
    Serial.println(" lux");

    // Check if lux value is below 300
    if (lux < 300) {
      Serial.println("Light has defect: Lux value below 300.");
    }
  }
}
