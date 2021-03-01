#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <Arduino.h>


void init_Serial()
{
	Serial.begin(9600);
}

void msg_inicio()
{
	delay(500);
    Serial.println("\n			-------	ESP8266	---- ROBOT CINTRA -- MQTT SENDER	-------");
}

void msg_n_serie(long n)
{
    Serial.print("\n	-----	ITERACIÓN N° "); Serial.print(n); Serial.println("	-----");
}