# RoboCom-CINTRA
Códigos fuente del "Sistema de Comunicación MQTT para el Robot Autónomo del CINTRA" UTN FRC


# Levantar el BROKER / Server MQTT
**Levantar el Broker/Server MQTT en un equipo con Sistema Operativo Linux**. Puede ser tanto una computadora normal como Raspberry Pi, funciona en ambos casos siempre y cuando se tenga Linux como Sistema Operativo.
1) Abra un terminal o shell en Linux:
```
sudo apt update
sudo apt install mosquitto
```
Con este comando se instala el software Mosquitto e inicia automáticamente, por lo que con estos simples comandos ya tenemos Levantado el Broker.
2) Ahora resta saber en que ***Address IP*** y ***Puerto*** se encuentra nuestro Broker. Por defecto Mosquitto usa el puerto **1883** y la dirección IP es la dirección IP propia del equipo donde está instalado mosquitto por lo que para saber la ip de nuestro equipo simplemente hacemos:
```
ip address
```
3) Por último podemos comprobar si realmente hemos levantado el Broker consultando el servicio de Mosquitto:
```
systemctl status mosquitto
```

# Testeos de mensajería del Broker
Podemos testear que tan bien anda nuestra red enviando y recibiendo mensajes por MQTT utilizando la Terminal de Linux (podemos utilizar cualquier computadora que esté en la red local para probar, inclusive la propia computadora local). Para esto debemos instalar unas herramientas de mosquitto llamadas *mosquitto-clients*
```
sudo apt-get install mosquitto-clients
```
Con esto ya podemos enviar y recibir mensajes desde la terminal de Linux.
## Ejemplo simple de comunicación MQTT
Primero Publicaremos un Mensaje.
1) Publicar un Mensaje:
```
mosquitto_pub -h 192.168.1.115 -p 1883 -t 'Aceler_X' -m "3.34"
```
Ahi podemos ver que hemos ***PUBLICADO*** un mensaje con el contenido *'20.34'* al ***topic*** *'temperatura_cupula'*.

Sin embargo como no tenemos ningún suscriptor a ese topic, ese mensaje nunca fue leído.

2) Ahora seremos Suscriptores del ***topic*** *'temperatura_cupula'*
```
mosquitto_sub -h 192.168.1.115 -p 1883 -v -t 'Aceler_X'
```
De este modo la Terminal queda ***SUSCRIPTO al TOPIC 'temperatura_cupula'*** a la espera de la publicación de un nuevo mensaje.

3) Dejamos abierto este terminal y ejecutamos nuevamente el paso 1 en un nuevo terminal
```
mosquitto_pub -h 192.168.1.115 -p 1883 -t 'Aceler_X' -m "3.34"
```
4) Ahora si volvemos al terminal suscriptor podremos ver el mensaje que hemos publicado.

Estos comandos podemos repetirlos en cualquier computadora de nuestra red y funcionará exactamente igual. Cualquier computadora de la red puede Publicar y ser Suscriptor sin restricciones.

# Nota Importante
Un Mensaje enviado por MQTT no se guarda en ningun lugar. Es decir, si en el momento en que fue publicado en cierto topic no había ningún suscriptor escuchando ese topic el mensaje simplemente se pierde.
