# ESP8266 Sender - Envío de los datos sensados en la IMU

# Procedimiento
Se explicará el procedimiento para instalar el software necesario, descargar el repositorio, configurar los archivos y poder compilar y cargar el firmware al ESP8266.
Solo se necesita un ESP8266 y un Broker activo en la red local (se necesita saber su address y su puerto para poder enviar a él)

## 1) Instalar Visual Studio Code
Primero debemos descargar **visual Code**, recomiendo instalar desde *snap* y no desde *apt-get* ya que la instalacion de *snap* es mas completa para este software:
```
sudo snap install vscode --classic
```
## 2) Instalar PlatformIO en Visual Studio Code
Abrimos Visual Studio Code en la barra de tareas vamos a *View/Extensions*, Se abre un pequeño buscador, inserte PlatformIO IDE, e instálelo.
## 3) Descargar Repositorio con el código.
Puede descargarlo desde la página de Github o simplemente con el comando:
```
git clone https://github.com/Gustbel/RoboCom-CINTRA
```
(Necesitará tener instalado el paquete git para esto: ```sudo apt install git```).
## 4) Abra el proyecto descargado en PlatformIO
Luego de instalar PlatformIO un nuevo ícono se agregará en la barra lateral izquierda del Visual Code, por favor haga click en el, asegúrese de estar en la pantalla *Home* de PlatformIO y seleccione la opción ***Open Project***.

Luego de esto se abrirá una ventana. Debe ir a donde fue clonado este repositorio y seleccionar la carpeta *'esp-robot-sender'*

## 5) Modifique el archivo 'include/config.h'
El archivo *config.h' contiene todas las configuraciones que determinan el funcionamiento del ESP8266, aquí configurará: la configuración de Red WiFi a la que se 
quiere conectar y si desea ip fija o no, la dirección y puerto del Broker MQTT, el modo en que se ejecutará (si es el sender del telescopio o el de la cúpula) y 
por último el intervalo de tiempo entre toma de datos.
```
/* Device */
const char* id_name = "ESP-ROBOT-CINTRA";

/* WiFi Network Configuracion */
const char* ssid_WiFi = "mySSID";
const char* pass_WiFi = "myPASS";

bool isEnable_IPfija = true;		/*   Setear en True en caso de necesitar IP Fija   */
IPAddress ip_WiFi(192,168,1,160); 		
IPAddress gateway_WiFi(192,168,1,1); 	/*   En caso de NO utilizar IP Fija ignore los valores ya que no seran tenidos en cuenta  */
IPAddress subnet_WiFi(255,255,255,0);


/* MQTT Broker Configuracion */
const char* address = "192.168.1.115";  /* Broker address (MQTT), No debe incluir 'http://xxx' o 'tcp://xxx' */
int port = 1883;
const char* user = "";			/* MQTT user */			/* En caso de que el Broker necesite autenticación */
const char* password = "";	/* MQTT password */

/* Intervalo de tiempo entre toma-envio de datos */
long interval = 8;    /* Tiempo en segundos */
```
## 6) Compile y Carge el Firmware en su ESP8266 con PlatformIO IDE
En PlatformIO haga click en ***Build*** para compilar, y una vez compilado presionamos en ***Upload and Monitor*** que además nos abrirá el Monitor Serial automáticamente
luego de cargar el Firmware para hacer un Debug en tiempo real.

Con esto ha finalizado el Setting del dispositivo. Los siguientes pasos son opcionales y son para debugueo.
## 7) Comprobación de Envío de Datos.
La forma más facil de comprobar el buen funcionamiento es suscribirse a uno de los topics a los que envía datos el sender. Por ejemplo, podemos suscribirnos al topic ***'Aceler_X'***.

Simplemente ejecutamos en cualquier computadora de nuestra red el siguiente comando:
```
mosquitto_sub -h 192.168.1.XXX -p 1883 -v -t 'Aceler_X'
```
De este modo nos hemos suscripto al topic del Broker y estamos a la espera de los mensajes enviados por el ESP8266 a ese topic.
