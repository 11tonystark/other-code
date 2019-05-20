#include <Wire.h>
#include "Adafruit_SGP30.h"
#include "MQ131.h"
Adafruit_SGP30 sgp;


// Init the sensor
// - Heater control on pin 2
// - Sensor analog read on pin A0
// - Model LOW_CONCENTRATION
// - Load resistance RL of 10KOhms (10000 Ohms)
MQ131 sensor(22,A0, LOW_CONCENTRATION,10000);


uint32_t getAbsoluteHumidity(float temperature, float humidity) {
    // approximation formula from Sensirion SGP30 Driver Integration chapter 3.15
    const float absoluteHumidity = 216.7f * ((humidity / 100.0f) * 6.112f * exp((17.62f * temperature) / (243.12f + temperature)) / (273.15f + temperature)); // [g/m^3]
    const uint32_t absoluteHumidityScaled = static_cast<uint32_t>(1000.0f * absoluteHumidity); // [mg/m^3]
    return absoluteHumidityScaled;
}

void setup() {
  Serial.begin(38400);
  Serial.println("SGP30 test");

  if (! sgp.begin()){
  //  Serial.println("Sensor not found :(");
    while (1);
  }
 // Serial.print("Found SGP30 serial #");
 //Serial.print(sgp.serialnumber[0], HEX);
// Serial.print(sgp.serialnumber[1], HEX);
 // Serial.println(sgp.serialnumber[2], HEX);

  
  //sgp.setIAQBaseline(0x8E68, 0x8F41);  python ka address file copy

   Serial.println("Calibration in progress...");

  sensor.calibrate();

  Serial.println("Calibration done!");
 // Serial.print("R0 = ");
  //Serial.print(sensor.getR0());
  //Serial.println(" Ohms");
  //Serial.print("Time to heat = ");
  Serial.print(sensor.getTimeToRead());
  Serial.println(" s");
}

int counter = 0;
void loop() {
  
  //float temperature = 22.1; // [°C]
  //float humidity = 45.2; // [%RH]
  

  if (! sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    return;
  }
  Serial.print("TVOC "); Serial.print(sgp.TVOC); Serial.print(" ppb\t");
  Serial.print("eCO2 "); Serial.print(sgp.eCO2); Serial.println(" ppm");
  delay(100);

  counter++;
  if (counter == 30) {
    counter = 0;

    uint16_t TVOC_base, eCO2_base;
    if (! sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
      Serial.println("Failed to get baseline readings");
      return;
    }
    Serial.print("****Baseline values: eCO2: 0x");
    //Serial.print(eCO2_base, HEX);
    //Serial.print(" & TVOC: 0x"); Serial.println(TVOC_base, HEX);

    sensor.begin();


if (! sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    return;
  }
  Serial.print("TVOC "); Serial.print(sgp.TVOC); Serial.print(" ppb\t");
  Serial.print("eCO2 "); Serial.print(sgp.eCO2); Serial.println(" ppm");
  delay(100);

  counter++;
  if (counter == 30) {
    counter = 0;

    uint16_t TVOC_base, eCO2_base;
    if (! sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
      Serial.println("Failed to get baseline readings");
      return;
    }
    Serial.print("****Baseline values: eCO2: 0x");
    //Serial.print(eCO2_base, HEX);
    //Serial.print(" & TVOC: 0x"); Serial.println(TVOC_base, HEX);

  }
  Serial.print("Concentration O3 : ");
  Serial.print(sensor.getO3(PPM));
  Serial.println(" ppm");
  Serial.print("Concentration O3 : ");
  Serial.print(sensor.getO3(PPB));
  Serial.println(" ppb");
   delay(20);
  }
}
