#ifndef STRUCT_DATOS_H_
#define STRUCT_DATOS_H_

#include <stdio.h>
#include <stdbool.h>

#define TAM_STR_DATO 32  /* Tamaño en Bytes del string de cada dato */

struct struct_data {
	char dato[TAM_STR_DATO];    /* String de Dato */
	char topic[TAM_STR_DATO];   /* String del topic MQTT */
}; 

#endif
