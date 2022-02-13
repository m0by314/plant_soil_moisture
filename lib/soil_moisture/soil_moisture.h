/** 
 * Library to manage soil moisture sensor
 * Tested with captor YL69 and module HC-38
*/
#ifndef _SOIL_SENSOR_H_
#define _SOIL_SENSOR_H_

#define N_MEASURE 3     // Number of measures performed by the sensor to make an average 

#define HIGH_VALUE 4095 
#define LOW_VALUE 0  
#define MIN 0
#define MAX 100

int get_soil_moisture(int sensor_pin, bool debug=false);

#endif