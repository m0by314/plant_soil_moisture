#ifndef _CONFIG_H_
#define _CONFIG_H_

// Sensor pin
#define MOISTURE_SENSOR_PIN 36 

/* Sleep Time */
#define HOUR_TO_SLEEP 6ULL                        /* Sleep time between each measurement  */
#define uS_TO_S_FACTOR 1000000                    /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP (HOUR_TO_SLEEP * 60 * 60)  /* Time ESP32 will go to sleep (in seconds) */

/* 
Moisture Sensor Calibration 
See this link https://www.hackster.io/m0by314/calibrate-soil-moisture-sensor-3c3a39 for cabribrate moisture sensor 
*/ 
#define DRY_VALUE "YOUR DRY VALUE"   /* Replace with the value obtained in dry soil */
#define WET_VALUE "YOUR WET VALUE"   /* Replace with the value obtained in wet soil */
#define MIN 0
#define MAX 100

/* WIFI Setting */
#define WIFI_SSID "YOUR_WIFI_SSID"     /* Replace with your wifi ssid. */
#define WIFI_PWD "YOUR_WIFI_PASSWORD"  /* Replace with your wifi password */

/* Adafruit IO settings */
#define IO_USERNAME "YOUR ADAFRUIT USERNAME" /* Replace with your adafruit username. */
#define IO_KEY "YOUR ADAFRUIT KEY"           /* Replace with your adafruit key.      */
#define IO_FEED_NAME "YOUR FEED NAME"        /* Replace with your adafruit feed name. */

#endif 