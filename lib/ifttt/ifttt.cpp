#include "ifttt.h"

#include <unistd.h>
#include <Client.h>


#define HOST "maker.ifttt.com"
#define SSL_PORT 443


/**
 * Constructor
*/
IFTTT::IFTTT (const char* ifttt_key, Client &client) {
    this->_key = ifttt_key;
    this->_client = &client;
}

/**
 * Send trigger to IFTTT webhook
 * 
 * @param eventName Webhook event name
 * @param value1 value passed to webhook
 * @param value2 value passed to webhook
 * @param value3 value passed to webhook
 * @param debug   if true displays the debugging messages by default false
 * 
 * @return true when trigger event is correctly sent
*/
bool IFTTT::triggerEvent(String eventName , String value1, String value2, String value3, bool debug){
    String response = "";
    String payload = _build_payload(value1,value2,value3, debug);
    int payload_len = payload.length();

    if (!_client->connect(HOST, SSL_PORT)) {
        if (debug) Serial.println("Connection failed!");
        _client->stop();
    }
    else {
        if (debug) Serial.println("Connected to server!");
        
        // Make a HTTP request:
        _client->println("POST /trigger/"+eventName+"/with/key/"+_key + " HTTP/1.1");
        
        // Headers
        _client->print("Host:"); _client->println(HOST);
        _client->println("Content-Type: application/json");
        _client->print("Content-Length: "); _client->println(payload_len);
        _client->println("Connection: Close");
        _client->println();

        // POST message body
        _client->println(payload);
        _client->println();
    
        // Wait for server response
        while (_client->available() == 0);

	    while (_client->available()) {
		    char c = _client->read();
            response = response + c;
	    }
    }
    if (debug) {
        Serial.println("Response:");
        Serial.println(response);
    }
    return _check_response_success(response);
}

/**
 * Verify response success
 * 
 * @param response response provide by the client
 * @return true in case of sucess
 */
bool IFTTT::_check_response_success(String response) {

  int index = response.indexOf("Congratulations!");

  return index > -1;
}


/**
 * Build content
 * @param value1 value passed to webhook
 * @param value2 value passed to webhook
 * @param value3 value passed to webhook
 * @param debug  if true displays the debugging messages by default false
 * 
 * @return payload
*/ 
String IFTTT::_build_payload(String value1, String value2, String value3, bool debug) {
    String payload = "{";
    if (value1) {
        payload = payload + "\"value1\":\"" + value1;
    }
    if (value2) {
        payload = payload + "\",\"value2\":\"" + value2;
    }
    if (value3) {
        payload = payload + "\",\"value3\":\"" + value3;
    }
    payload += "\"}";

    if (debug) {
        Serial.println("Payload:");
        Serial.println(payload);
    }
    return payload;
}

