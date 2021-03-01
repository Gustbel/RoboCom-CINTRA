#ifndef _MQTT_H_
#define _MQTT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <struct-data.h>

void reconnect_MQTT(const char* addr, int p, const char* us, const char* pw);
void init_MQTT(const char*, int, const char*, const char*);
void publica_MQTT(struct struct_data *data);

#endif
