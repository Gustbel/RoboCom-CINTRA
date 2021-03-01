#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <struct-data.h>
#include <Arduino.h>

WiFiClient espClient;
PubSubClient client(espClient);

void reconnect_MQTT(const char* addr, int p, const char* us, const char* pw)
{
    while(client.connected() != 1)
    {
        Serial.print("\n   ---   ERROR al conectar al Broker MQTT  -- ERROR: ");
        Serial.print(client.state());
        Serial.println("   ---");

        client.setServer(addr, p);
        client.connect("", us, pw);
        delay(3000);
    }
}

void init_MQTT(const char* addr, int p, const char* us, const char* pw)
{
    Serial.print("\nConectando a Broker MQTT en: "); Serial.println(addr);
    
    client.setServer(addr, p);
    client.connect("", us, pw);
    
    if (client.connected() != 1)
    {
        reconnect_MQTT(addr, p, us, pw);
    }
    Serial.println("\n   ---   Conectado!! enviando datos al Broker MQTT   ---");
}

void publica_MQTT(struct struct_data *data)
{
    client.publish(data->topic, data->dato);
    Serial.print("Publicado: "); Serial.print(data->dato); Serial.print(" en topic: /"); Serial.println(data->topic);
    delay(300);
}

