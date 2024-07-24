# Librería de MentorBit

Esta librería está construida por Digital Codesign para utilizar junto con el kit educacional "MentorBit". La librería se compone de ocho clases diferentes que permiten utilizar las diferentes funcionalidades del MentorBit a través de varias funciones y ejemplos.

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)


# Modo de empleo
Cuando tengas la librería instalada, debes incluir la librería al comienzo de tu sketch, antes del setup, con la siguiente línea:

   ``#include  "MentorBit.h"``

En función del módulo que quieras utilizar, deberás importarlo de la misma manera que en el ejemplo.

### Constructor

Crea una instancia de la clase con el nombre que más te guste, nosotros usaremos en este caso "miMentorBit". Al constructor del MentorBit solo debemos indicarle el nombre de la instancia (No olvidar el ;)

``MentorBit miMentorBit;``

Ahora podemos emplear las propiedades y métodos de nuestro objeto miMentorBit. La librería incluye varios módulos importables cuyo constructor coincidirá con el nombre del módulo.

### Elementos del MentorBit
Hay una serie de elementos que vienen incluidos en el MentorBit como Leds, Pulsadores, etcétera. Para referirnos a cada uno de ellos en nuestro código debemos emplear el nombre que se le ha dado en la librería. Podemos mirar la siguiente tabla para ver la relación entre los elementos y sus nombres de referencia.
| Módulo | Elemento | Nombre de ref. |
|:--|:--|:--|
| MentorBit |Led de color Rojo | ledRojo |
| MentorBit |Led de color Verde | ledVerde |
| MentorBit |Led de color Azul | ledAzul|
| MentorBit |RGB elemento Rojo | rgbRojo |
| MentorBit |RGB elemento Verde | rgbVerde |
| MentorBit |RGB elemento Azul | rgbAzul | 
| MentorBit |Pulsador Digital (PullUP) | pulsadorPullUpDigital|
| MentorBit |Pulsador Digital (PullDOWN) |pulsadorPullDownDigital |
| MentorBit |Pulsador Analógico (PullUP) |pulsadorPullUpAnalogico |
| MentorBit |Pulsador Analógico (PullDOWN) | pulsadorPullDownAnalogico |
| MentorBit |Zumbador | zumbador |
| MentorBit |Potenciómetro | potenciometro |
| MentorBitSensores |Fotorresistencia | ldr |
| MentorBitSensores |Sensor de gases MQ | mq |
| MentorBitSensores |Sensor de temperatura y humedad | dht |
| MentorBitSensores |Sensor de temperatura | ds18b20 |
| MentorBitSensores |Sensor ultrasonidos (Pin de Echo) | ultrasonidosEcho |
| MentorBitSensores |Sensor ultrasonidos (Pin de Trigger) | ultrasonidosTrigger |
| MentorBitMotores |Servomotor | servomotor |
| MentorBitMotores |Motor DC (Enable) | enableDC |
| MentorBitMotores |Motor DC (Entrada 1) | entrada1DC |
| MentorBitMotores |Motor DC (Entrada 2) | entrada2DC |
| MentorBitMotores |Motor Paso a Paso (Bobina 1) | bobina1PAP |
| MentorBitMotores |Motor Paso a Paso (Bobina 2) | bobina2PAP |
| MentorBitMotores |Motor Paso a Paso (Bobina 3) | bobina3PAP |
| MentorBitMotores |Motor Paso a Paso (Bobina 4) | bobina4PAP |
| MentorBitPantallas |Pantalla LCD | lcd |
| MentorBitPantallas |Pantalla OLED | oled |
| MentorBitDataLogger |Pin selector de tarjeta SD | chipSelectSD |
| MentorBitDataLogger |Reloj en Tiempo Real (RTC, Real Time Clock) | rtc |
| MentorBitPuertos |Pin digital Y del Puerto X (del 0 al 6) | puertoX_digitalY |
| MentorBitPuertos |Pin analógico Y del Puerto X (del 0 al 2) | puertoX_analogY |

### Ejemplos
Dispones de ejemplos de diferentes dificultades para ir probando y experimentando con los distintos componentes del MentorBit (LEDs, pulsadores, zumbador, etc.). Aquí tienes una lista con todos los que hay y qué puedes hacer con ellos:

|Ejemplo |  Descripción  |
|--|--|
|LedDeColores | Encendido secuencial de los LEDs |
|LedRGB | Encendido secuencial y combinado del RGB |   
|Potenciometro | Se toman lecturas del potenciómetro |    
|PulsadoresAnalógicos | Se captura el input analógico del pulsador |    
|PulsadoresDigitales | Se captura el input digital del pulsador |   
|Zumbadores | Generación de tonos con el zumbador. |
|RTC | Establecer la hora manualmente y automáticamente  | 
|TarjetaSD | Escribir y leer sobre un archivo de la tarjeta.  |
|Display7Segments | Muestra varios valores en el display|
|MotorDC |  Controla el motor de corriente continua |
|MotorPasoAPaso | Controla el motor Paso a Paso |
|Servomotor | Controla el servomotor |
|LCD | Muestra por la pantalla el mensaje "Hello, world!". |
|OLED | Muestra por la pantalla el icono por defecto. |
|DHT | Recogida de la información del sensor y volcado en Serial |
|DS18B20 | Recogida de temperatura del sensor |
|LDR | Lectura de la fotorresistencia |
|MQ | Encendido de un LED utilizando la medida del MQ |
|Ultrasonidos | Recogida de la distancia entre objecto y sensor |
|Puerto_1 | Encendido secuencial de los pines del puerto 1 |
|Puerto_2 | Encendido secuencial de los pines del puerto 2 |
|Puerto_3 | Encendido secuencial de los pines del puerto 3 |


# Ficheros

En esta versión se cuenta con quince archivos principales en la librería : 
- MentorBit.cpp
- MentorBit.h
- MentorBitDataLogger.cpp
- MentorBitDataLogger.h
- MentorBitDisplay.cpp
- MentorBitDisplay.h
- MentorBitMotores.cpp
- MentorBitMotores.h
- MentorBitPantallas.cpp
- MentorBitPantallas.h
- MentorBitPuertos.cpp
- MentorBitPuertos.h
- MentorBitSensores.cpp
- MentorBitSensores.h

## MentorBit

Librería base para MentorBit Arduino. Contiene la definición de la clase base MentorBit, que es referida al MentorBit compatible con Arduino.

El constructor de la clase provee una instancia de la clase MentorBit con los pines de conexión de los elementos básicos de la placa.
* LED de colores

* LED RGB

* Pulsadores

*  Zumbador

*  Potenciómetro

## MentorBitDataLogger

Librería del módulo de DataLogger (SD y RTC) para MentorBit Arduino. En ella se declaran los atributos y métodos para la clase MentorBitDataLogger,
El constructor de la clase devuelve una instancia de la clase MentorBitDataLogger que provee los pines y métodos necesarios para controlar la tarjeta SD y el RTC en el MentorBit.

``MentorBitDataLogger() {
	chipSelectSD = PIN_A6;
}``

Cuenta con siete funciones que nos permiten un mejor manejo de la información.
* `` String leerDeArchivo(String nombre) ``
Devuelve una cadena de texto con el contenido del archivo o una cadena vacía si no es capaz de realizar la lectura.

* `` boolean escribirEnArchivo(String nombre,  String mensaje) ``
Devuelve un booleano, true si consigue realizar la escritura correctamente y false si no es capaz de hacerlo.

* `` boolean  inicializarSD() ``
Inicializa la tarjeta SD y devuelve **TRUE** cuando se haya realizado el procedimiento haya funcionado correctamente. Devuelve **FALSE** en otro caso  

* `` String  obtenerHoraRTC() ``
Devuelve la hora actual en formato de cadena de texto

* `` void  ajustarHoraRTC() ``
Ajusta la hora del RTC a la hora del sistema

* `` void  ajustarHoraRTC (uint16_t anyo, uint8_t mes, uint8_t dia, uint8_t hora=0, uint8_t minuto=0, uint8_tsegundo=0) ``
Función para ajustar la hora del RTC a la hora dada.

* `` boolean inicializarRTC() ``
Devuelve un booleano, **TRUE** si consigue inicializar correctamente y **FALSE** si no es capaz de hacerlo.
 

## MentorBitDisplay

Librería del módulo de Display para MentorBit Arduino. En ella se define de la clase MentorBitDisplay, referida al MentorBit compatible con Arduino y el módulo de display 7 segmentos.

Incluido su constructor e inicializador cuenta con el métodos imprimir:
* `` MentorBitDisplay() ``
Devuelve una instancia de la clase MentorBitDisplay que provee las direcciones y métodos necesarios para controlar el display 7 segmentos integrado en el MentorBit

* `` void inicializarDisplay() ``

El método `` void imprimir(X valor) ``está sobrecargado para funcionar con los siguientes tipos de datos
* int
* double
* char
* string


## MentorBitMotores

Librería del módulo Motores para MentorBit Arduino. Definición de la clase MentorBitMotores, referida al MentorBit compatible con Arduino y el módulo de Motores.
* `` MentorBitMotores() ``
* `` void inicializarServo() ``

Una vez inicializado el Servo se provee de tres funciones que permiten manejar los diferentes motores.
* `` void moverServo(uint16_t grados) ``
* `` void moverMotorDC(uint8_t velocidad,  uint8_t direccion) ``
* `` void moverMotorPP(uint16_t pasos,  uint8_t direccion) ``


## MentorBitPantallas

Definición de la clase MentorBitPantallas, referida al MentorBit compatible con Arduino y el módulo de pantallas.
* `` MentorBitPantallas() ``
Devuelve una instancia de la clase MentorBitPantallas que provee las direcciones de conexión de los pantallas de la placa y un objeto para utilizarlas.

* `` void inicializarLCD() ``
* `` void inicializarOLED() ``


## MentorBitPuertos

Librería de los puertos genéricos para MentorBit Arduino. Definición de la clase base MentorBitPuertos, que hace referencia a los diferentes puertos que forma parte del MentorBit compatible con Arduino de forma genérica.

La clase cuenta con un constructor ``MentorBitPuertos()`` que devuelve una instancia de la clase MentorBitPuertos que provee los pines de conexión de los conectores de los puertos.
*  Puerto genérico 1
*  Puerto genérico 2
*  Puerto genérico 3
Cada uno compuesto de seis puertos digitales y dos analógicos.


## MentorBitSensores

Librería del módulo Sensores para MentorBit Arduino. Definición de la clase MentorBitSensores, referida al MentorBit compatible con Arduino y el módulo de sensores.

``MentorBitSensores()``
 Devuelve una instancia de la clase MentorBitSensores que provee los pines de conexión de los sensores de la placa y los puertos correspondientes. También provee de los métodos necesarios para obtener las lecturas de cada sensor de manera sencilla.
*  DS18B20

*  DHT

*  LDR

*  HC-SR04

``uint8_t  obtenerLecturaLDR()``
Devuelve un valor entero con la lectura obtenida de la fotorresistencia

``uint8_t obtenerLecturaMQ()``
Devuelve un valor entero con la lectura obtenida en el pin donde se encuentra conectado el MQ.
  
``float  obtenerTemperaturaDHT()``
  Devuelve un valor decimal con la lectura de la temperatura en Centígrados obtenida en el pin donde se encuentra conectado el DHT.

``float obtenerHumedadDHT()``
Devuelve un valor decimal con la lectura correspondiente a la humedad en un formato de porcentaje obtenida en el pin donde se encuentra conectado el DHT.
  
``float  obtenerTemperaturaDS18B20()``
Devuelve un valor decimal con la lectura en Centígrados obtenida en el pin donde se encuentra conectado el DS18B20.

``uint16_t  obtenerDistanciaUlrasonidos()``
Devuelve un valor entero con la lectura en Centímetros obtenida con los pines donde se encuentra conectado el HC-SR04 (Ultrasonidos).
