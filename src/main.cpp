#include <Arduino.h>
#include <AdafruitIO_WiFi.h>
#include <WiFiClientSecure.h>

#include <ifttt.h>
#include <soil_moisture.h>
#include "../config.h"


// Prototype
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PWD);  // Set up the adafruit WiFi client.
AdafruitIO_Feed *moisture = io.feed(IO_FEED_NAME); // Set up the feed.
WiFiClientSecure client;


IFTTT ifttt_mail(IFTTT_KEY, client);   // Initialize Ifttt object.


void setup() {
  Serial.begin(115200);
  
  pinMode(MOISTURE_SENSOR_PIN,INPUT);
  adcAttachPin(MOISTURE_SENSOR_PIN);
  
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);  // Timer for the wakeup of the ESP

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  int timeout = 10;
  while(io.status() < AIO_CONNECTED && (timeout-- > 0)) {
    Serial.print(".");
    sleep(1);
  }
  if (io.status() < AIO_CONNECTED) {
    Serial.println();
    Serial.println("ERROR: Adafruit IO fail connection");
    esp_deep_sleep_start();
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  
  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  // Read Sensor
  float soil_moisture_percent = get_soil_moisture_percent(MOISTURE_SENSOR_PIN);
  
  // Send mail when the percentage of soil moisture lower than your threshold
  if (soil_moisture_percent <= int(THRESHOLD)) {
    // Built the mail 
    String mail_object = String(PLANT_NAME) + " must be watered";
    String mail_body = "The " + String(PLANT_NAME) + " must be watered, the percentage of soil moisture is: " + String(soil_moisture_percent) + ".<br>";

    // Send mail
    ifttt_mail.triggerEvent(IFTTT_EVENT_NAME, MAILTO, mail_object, mail_body);
  }

  // Send data to the feed.
  moisture->save(soil_moisture_percent);

  // Start deep sleep
  Serial.println("Going to sleep ...\n");
  delay(5000);
  esp_deep_sleep_start();
}

void loop(){
}