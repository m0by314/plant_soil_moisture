#include "soil_moisture.h"

#include <Arduino.h>

/**
* Get the percentage of soil moisture
*
* @param sensor_pin   soil moisture sensor pin 
* @param debug        if true displays the debugging messages, by default debug=false
*
* @return soil moisture percentage
*/
int get_soil_moisture(int sensor_pin, bool debug) {
  int soil_moisture;
  int raw_data = 0;

  digitalWrite(sensor_pin, HIGH);  // Sets the sensor to on 
  delay(500);
  
  if (debug) Serial.println("Reading From the Sensor ...");
  for (int i = 0; i < N_MEASURE; i++){  // Reads the sensor "N" times, by default N_MEASURE=3
    raw_data += analogRead(sensor_pin);
    delay(150);
  }

  digitalWrite(sensor_pin, LOW); // Sets the sensor to off
  
  raw_data = raw_data / N_MEASURE;  // Averages the data obtained by the sensor 
  soil_moisture = map(raw_data, HIGH_VALUE, LOW_VALUE, MIN, MAX);  // Calculates the percentage of humidity

  if (debug) {
      Serial.printf("Raw sensor data: %i\n", raw_data);
      Serial.printf("Soil moisture : %i%%\n", soil_moisture);
  }
  return soil_moisture;
}