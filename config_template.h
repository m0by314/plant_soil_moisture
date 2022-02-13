#ifndef _CONFIG_H_
#define _CONFIG_H_

// Sensor pin
#define MOISTURE_SENSOR_PIN 36 

/* Sleep Time */
#define HOUR_TO_SLEEP 6ULL                        /* Sleep time between each measurement  */
#define uS_TO_S_FACTOR 1000000                    /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP (HOUR_TO_SLEEP * 60 * 60)  /* Time ESP32 will go to sleep (in seconds) */

/* WIFI Setting */
#define WIFI_SSID "YOUR_WIFI_SSID"     /* Replace with your wifi ssid. */
#define WIFI_PWD "YOUR_WIFI_PASSWORD"  /* Replace with your wifi password */

/* Plant name */
#define PLANT_NAME "YOUR PLANT NAME"   /* Replace with your plant name, use for the subject of the mail.*/

/* Adafruit IO settings */
#define IO_USERNAME "YOUR ADAFRUIT USERNAME" /* Replace with your adafruit username. */
#define IO_KEY "YOUR ADAFRUIT KEY"           /* Replace with your adafruit key.      */
#define IO_FEED_NAME "YOUR FEED NAME"        /* Replace with your adafruit feed name. */

// IFTTT Setting
#define IFTTT_KEY  "YOUR_IFTTT_KEY"          /* Replace with your unique IFTTT Key, can be obtained at this link: https://ifttt.com/maker_webhooks/settings. */
#define IFTTT_EVENT_NAME "YOUR_EVENT_NAME"  /* Replace with your IFTTT event name. */

/* Mail Setting */
#define MAILTO "YOUR_MAIL" /* Replace with your email. */

/* Moisture alert threshold */
#define THRESHOLD "YOUR_MOISTURE_THRESHOLD" /* Replace with your moisture threshold alert */

#endif 
