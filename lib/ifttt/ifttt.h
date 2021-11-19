/** 
 * Object allowing to send a trigger to an IFTTT webhook with an ESP32
 * 
 * Exemple: 
 *      #define IFTTT_KEY "zzzzzzzzzzzzzzzzzzzzzzz"
 *      #define IFTTT_EVENT_NAME "device_on"
 *      
 *      WiFiClientSecure client; 
 *      IFTTT ifttt(IFTTT_KEY, client);
 *
 *      Ifttt.triggerEvent(EVENT_NAME, value1, value2, value3); //returns true if successful
 *      //triggerEvent takes an Event Name and then you can optional pass in up to 3 extra Strings
*/
#ifndef _IFTTT_H_
#define _IFTTT_H_

#include <Arduino.h>
#include <Client.h>


#define HOST "maker.ifttt.com"
#define SSL_PORT 443


class IFTTT {
    public:
        IFTTT(const char* ifttt_key, Client &client);
        bool triggerEvent(String eventName , String value1, String value2, String value3, bool debug=false);

    private:
        const char* _key;
        Client *_client;

        String _build_payload(String value1, String value2, String value3, bool debug=false);
        bool _check_response_success(String response);
};

#endif