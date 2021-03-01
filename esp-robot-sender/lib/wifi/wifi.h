#ifndef _WIFI_H_
#define _WIFI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ESP8266WiFi.h>

void init_wifi(const char*,const char*, bool, IPAddress, IPAddress, IPAddress);

#endif