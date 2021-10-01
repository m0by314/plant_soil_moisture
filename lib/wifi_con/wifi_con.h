#ifndef _WIFI_CON_H_
#define _WIFI_CON_H_

#include <Stream.h>
#include <WiFi.h>

void wifi_connect(Stream *serial);

void wifi_disconnect();

#endif