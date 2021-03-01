#include <basic.h>
#include <config.h>
#include <wifi.h>
#include <mqtt.h>
#include <sensor_IMU.h>
#include <struct-data.h>

#define TAM_VECT_ACEL 3	/* Cantidad de datos que tiene el Sensor Acelerometro */
#define TAM_VECT_VELO 3	/* Cantidad de datos que tiene el Sensor de Velocidad */
#define TAM_VECT_MAGN 3	/* Cantidad de datos que tiene el Sensor de Velocidad */

struct struct_data acelerometro[TAM_VECT_ACEL];   /* Se crean n estructuras de datos */
struct struct_data velocidad[TAM_VECT_VELO];
struct struct_data magnetometro[TAM_VECT_MAGN];

long n;

void setup() 
{
  /*************   INICIALIZACIONES   *************/
  init_Serial();  
  msg_inicio(); // Mensaje de inicio
  n = 0;  // Contador de iteraciones

  /** Inicializacion de Conexiones de la Infraestructura de Red **/
  init_wifi(ssid_WiFi, pass_WiFi, isEnable_IPfija, ip_WiFi, gateway_WiFi, subnet_WiFi);
  
  init_MQTT(address, port, user, password);

  /** Inicializacion de devices sensores **/
  init_IMU();

  /** Inicializacion de sensores -(Creacion de la estructura y a que topic MQTT corresp cada dato) **/
  strcpy(acelerometro[0].topic, "Aceler_X");
  strcpy(acelerometro[1].topic, "Aceler_Y");
  strcpy(acelerometro[2].topic, "Aceler_Z");

  strcpy(velocidad[0].topic, "Velocid_X");
  strcpy(velocidad[1].topic, "Velocid_Y");
  strcpy(velocidad[2].topic, "Velocid_Z");

  strcpy(magnetometro[0].topic, "Magnetom_X");
  strcpy(magnetometro[1].topic, "Magnetom_Y");
  strcpy(magnetometro[2].topic, "Magnetom_Z");
  /************************************************/


  /*************   INICIO LOOP   *************/
  while (true)
  {
    /*************   RECOPILACION DE DATOS (harcodeados por ahora)   *************/
    for(int i = 0; i < TAM_VECT_ACEL; i++) {
        strcpy(acelerometro[i].dato, get_acelerometro(i));  // Obtiene el dato en forma de char* (string) de la función del sensor
    }

    for(int i = 0; i < TAM_VECT_VELO; i++) {
        strcpy(velocidad[i].dato, get_velocidad(i));  // Obtiene el dato en forma de char* (string) de la función del sensor
    }

    for(int i = 0; i < TAM_VECT_MAGN; i++) {
        strcpy(magnetometro[i].dato, get_magnetometro(i));  // Obtiene el dato en forma de char* (string) de la función del sensor
    }

    /*************   ENVIO/PUBLICACION DE DATOS AL SERVER/BROKER en RASPBERRY   *************/
    msg_n_serie(++n);

    for(int i = 0; i < TAM_VECT_ACEL; i++) {
        publica_MQTT( &(acelerometro[i]) );
    }

    for(int i = 0; i < TAM_VECT_VELO; i++) {
        publica_MQTT( &(velocidad[i]) );
    }

    for(int i = 0; i < TAM_VECT_MAGN; i++) {
        publica_MQTT( &(magnetometro[i]) );
    }

    /*************   DELAY   ***************/    
    delay(interval * 1000);
  }
}

void loop() {
; // No utilizado
}