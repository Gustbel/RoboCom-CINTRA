#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <Arduino.h>


void init_IMU()
{
    //
    // Definición de inicialización del acelerometro I2C
    //

    Serial.println("-- Inicialización del Acelerometro Correcta");
}

char* get_acelerometro(int n) 
{
    char buffer[100];
    char* s = " ";
    float d;
    switch(n)
    {
        case 0:
        /* ADQUISICIÓN DEL DATO 0 - ACELERACION EN X - para guardarlo en 'd' */
        d = 0.23; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        case 1:
        /* ADQUISICIÓN DEL DATO 1 - ACELERACION EN Y - para guardarlo en 'd' */
        d = -2.73; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        case 2:
        /* ADQUISICIÖN DEL DATO 2 - ACELERACION EN Z - para guardarlo en 'd' */
        d = 3.19; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        default:
        return "";
    }
}

char* get_velocidad(int n) 
{
    char buffer[100];
    char* s = " ";
    float d;
    switch(n)
    {
        case 0:
        /* ADQUISICIÓN DEL DATO 0 - VELOCIDAD EN X - para guardarlo en 'd' */
        d = 12.4; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        case 1:
        /* ADQUISICIÓN DEL DATO 1 - VELOCIDAD EN Y - para guardarlo en 'd' */
        d = -6.2; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        case 2:
        /* ADQUISICIÖN DEL DATO 2 - ACELERACION EN Z - para guardarlo en 'd' */
        d = 16.9; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        default:
        return "";
    }
}

char* get_magnetometro(int n) 
{
    char buffer[100];
    char* s = " ";
    float d;
    switch(n)
    {
        case 0:
        /* ADQUISICIÓN DEL DATO 0 - MAGNETOMETRO EN X - para guardarlo en 'd' */
        d = -2.42; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        case 1:
        /* ADQUISICIÓN DEL DATO 1 - MAGNETOMETRO EN Y - para guardarlo en 'd' */
        d = 0.65; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        case 2:
        /* ADQUISICIÖN DEL DATO 2 - MAGNETOMETRO EN Z - para guardarlo en 'd' */
        d = -0.09; /* Harcodeado */
        /***********/
        sprintf(buffer, "%.02f", d);    // Se hace este rodeo de char*-char[]-char* para evitar errores de compilación
        s=buffer;
        return s;

        default:
        return "";
    }
}