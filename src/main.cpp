#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <Arduino.h>
#include <WiFi.h>

#include <ifttt.h>
#include <soil_moisture.h>
#include <adafruitIO.h>
#include "../config.h"


IFTTT ifttt(IFTTT_KEY);   // Initialize Ifttt object.
AdafruitIO adafruit_feed(IO_KEY, IO_USERNAME); 

void setup() {
  Serial.begin(115200);
  
  pinMode(MOISTURE_SENSOR_PIN,INPUT);
  adcAttachPin(MOISTURE_SENSOR_PIN);
  
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);  // Timer for the wakeup of the ESP

  WiFi.mode(WIFI_STA); //Optional
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  Serial.println("\nConnecting");
  int timeout = 0;
  while(WiFi.status() != WL_CONNECTED && timeout <= 10){
    Serial.print(".");
    delay(100);
    timeout++;
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());

  // Read Sensor
  float soil_moisture_percent = get_soil_moisture_percent(MOISTURE_SENSOR_PIN);
  
  // Send mail when the percentage of soil moisture lower than your threshold
  if (soil_moisture_percent <= int(THRESHOLD)) {
    // Built the mail 
    int len_object = strlen(PLANT_NAME) + strlen(" must be watered");
    char mail_object[len_object + 1 ];
    snprintf(
      mail_object, 
      len_object,
      "%s must be watered", PLANT_NAME
    );

    int len_body = strlen("The ") + strlen(PLANT_NAME) + strlen(" must be watered, the percentage of soil moisture is: ") + sizeof(soil_moisture_percent) + strlen(".<br>");
    char mail_body[len_body + 1 ];
    snprintf(
      mail_body, 
      len_body,
      "The %s must be watered, the percentage of soil moisture is: %f.<br>", PLANT_NAME, soil_moisture_percent
    );

    // Send mail
    ifttt.triggerEvent(IFTTT_EVENT_NAME, MAILTO, mail_object, mail_body);
  }
  
  // format data as str
  int len = sizeof(soil_moisture_percent);
  char buf[len + 1];
  snprintf(buf, len + 1, "%f", soil_moisture_percent);
  // update feed
  adafruit_feed.updateFeed(IO_FEED_NAME, buf);

  // Start deep sleep
  Serial.println("Going to sleep ...\n");
  delay(5000);
  esp_deep_sleep_start();
  
}

void loop(){
}