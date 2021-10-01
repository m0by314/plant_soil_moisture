#ifndef _CONFIG_H_
#define _CONFIG_H_

// Sensor pin
#define MOISTURE_SENSOR_PIN 36 

// Sleep Time
#define HOUR_TO_SLEEP 6                           /* Sleep time between each measurement  */
#define uS_TO_S_FACTOR 1000000                    /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SECOND (HOUR_TO_SLEEP * 60 * 60)  /* Time ESP32 will go to sleep (in seconds) */

/* 
Moisture Sensor Calibration 
See this link https://www.hackster.io/m0by314/calibrate-soil-moisture-sensor-3c3a39 for cabribrate moisture sensor 
*/ 
#define DRY_VALUE "YOUR DRY VALUE"   // Replace with the value obtained in dry soil 
#define WET_VALUE "YOUR WET VALUE"   // Replace with the value obtained in wet soil 
#define MIN 0
#define MAX 100

// WIFI Setting
#define WIFI_SSID "YOUR_WIFI_SSID"     // Replace with your wifi ssid.
#define WIFI_PWD "YOUR_WIFI_PASSWORD" // Replace with your wifi password

// Mail Setting
#define MAILTO "YOUR_MAIL" // Replace with your email.

#endif