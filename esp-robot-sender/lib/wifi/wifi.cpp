#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <ESP8266WiFi.h>
#include <Arduino.h>


void init_wifi(const char* ssid,const char* pass, bool isEnable, IPAddress ip, IPAddress gw, IPAddress sn)
{
    Serial.print("\nConectando a red "); Serial.print(ssid);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    if (isEnable == true)
        WiFi.config(ip, gw, sn); 

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.print("\nConectado a red WiFi! IP Address: ");
    Serial.println(WiFi.localIP());
}
