#include <chrono>
#include <thread>

#include <config.h>
#include "wifi_con.h"

using namespace std::chrono;

// Establish a Wi-Fi connection with your router
void wifi_connect(Stream *serial) {
    serial->print("Connecting to: "); 
    serial->print(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PWD);  
    
    int timeout = 10 * 4; // 10 seconds
    auto epoch = high_resolution_clock::from_time_t(0); // Time t0

    while(WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
        std::this_thread::sleep_for(milliseconds(250)); // sleep 250ms
        serial->print(".");
    }
    serial->println("");

    auto now   = high_resolution_clock::now(); // time after connection
    auto mseconds = duration_cast<milliseconds>(now - epoch).count(); // times for wifi connewction

    if(WiFi.status() != WL_CONNECTED) {
        serial->println("ERROR : WiFI fail connection");
    }
    else {
        serial->print("WiFi connected in: "); 
        serial->print(mseconds / 1000); 
        serial->print("s, IP address: "); 
        serial->println(WiFi.localIP());  
    }  
}
// disconnect WiFi connection
void wifi_disconnect(){
    WiFi.disconnect();
}