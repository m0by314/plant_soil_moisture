#include <Arduino.h>

#include <wifi_con.h>
#include <config.h>


int soil_moisture;
int soil_moisture_percent;

void setup() {
  Serial.begin(115200);

  pinMode(MOISTURE_SENSOR_PIN,INPUT);
  adcAttachPin(MOISTURE_SENSOR_PIN);

  wifi_connect(&Serial);
  //esp_sleep_enable_timer_wakeup(TIME_TO_SECOND * uS_TO_S_FACTOR);
  delay(2000); 
}
  

void loop() {
  soil_moisture = analogRead(MOISTURE_SENSOR_PIN);
  soil_moisture_percent = map(soil_moisture, DRY_VALUE, WET_VALUE, MIN, MAX); 
  Serial.printf("Moisture : %i%% ", soil_moisture_percent);
  delay(10000);
 
  //esp_deep_sleep_start();
}