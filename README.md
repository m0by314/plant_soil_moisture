# Plants soil moisture monitoring
Tool to plants soil moisture monitoring with Adafruit IO dashboard and an ESP32 with soil moisture sensor.

## Summary
 - [How it works](#How-it-works)
 - [Connect the soil moisture sensor](#Connect-the-soil-moisture-sensor)
 - [Calibrate your soil moisture sensor](#Calibrate-your-soil-moisture-sensor)
 - [Create IFTTT webhooks](#Create-IFTTT-webhooks)
 - [Create Adafruit IO dashboard](#Create-Adafruit-IO-Dashboard)
 - [Setup](#Setup)
 - [Built with](#Built-with)


## How it works

The tool performs a measurement every 6 hours, in order to have the evolution of the soil moisture during the day.  

If the percentage of soil moisture is below 25%, an alert is sent by email using an IFTTT webhook. 
  
The data is stored on an Adafruit IO feed to be visualized in a dashboard. 

Between each measurement, the ESP goes into deep sleep mode.  

## Connect the soil moisture sensor

![image](static/img/Soil_Moisture_Interfacing_Diagram.png)

## Calibrate your soil moisture sensor 

For more accuracy, the sensor should be calibrated with a sample of the plant's soil. 
Place a dry soil sample in a cup and use the calibration program available at this link: 
https://www.hackster.io/m0by314/calibrate-soil-moisture-sensor-3c3a39 

Once the calibration is finished you will receive an email with the threshold for dry soil. 

Water the sample and restart the program to obtain the threshold for wet soil.

## Create IFTTT webhooks

* Go to the link: https://ifttt.com/
* Then click on the "create" button 
![image](static/img/ifttt_create.png)
* Then click on "add" in the "If This" section 
![image](static/img/ifttt_add.png)
* Search for the "Webhooks" service
![image](static/img/ifttt_webhooks.png)
* Select trigger "Receive a web request"
![image](static/img/ifttt_web_request.png) 
* Define the event name (to keep aside it will be used in the configuration file) then create the trigger
![image](static/img/ifttt_event_name.png)
* In the "Then that" section click on "add
![image](static/img/ifttt_then.png)
* Search for the Gmail service
* Then select action "send an email"
![image](static/img/ifttt_mail.png)
* Complete action fields like this:
![image](static/img/ifttt_fields.png)


* Go to the following link to get your key: https://ifttt.com/maker_webhooks/settings   
The key is at the end of the URL
![image](static/img/ifttt_key.png)  


## Create Adafruit IO Dashboard

* See this link for create a feed: 
https://learn.adafruit.com/adafruit-io-basics-feeds/creating-a-feed
* See this link for create a feed: 
https://learn.adafruit.com/adafruit-io-basics-dashboards/creating-a-dashboard

* Get your Adafruit Key:
Click on the tab "My Key"
![image](static/img/adafruit_key.png)

* Get your Adafruit feed key:
Go to the feeds page to see the key of your feed
![image](static/img/adafruit_feed_key.png)


## Setup 


* First copy the template:  
`cp config_template.h config.h`

* Configure the following variables with your credentials:  
```
/* 
Moisture Sensor Calibration 
See this link https://www.hackster.io/m0by314/calibrate-soil-moisture-sensor-3c3a39 for cabribrate moisture sensor 
*/ 
#define DRY_VALUE "YOUR DRY VALUE"   /* Replace with the value obtained in dry soil */
#define WET_VALUE "YOUR WET VALUE"   /* Replace with the value obtained in wet soil */

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
```

## Built with

* ESP32 NodeMCU Module WLAN WiFi Development Board with CP2102 
* Moisture sensor YL69 and module HC-38
