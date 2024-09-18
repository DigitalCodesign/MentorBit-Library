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
| MentorBit | Led de color Rojo | LED_ROJO |
| MentorBit | Led de color Verde | LED_VERDE |
| MentorBit | Led de color Azul | LED_AZUL|
| MentorBit | RGB elemento Rojo | RGB_ROJO |
| MentorBit | RGB elemento Verde | RGB_VERDE |
| MentorBit | RGB elemento Azul | RGB_AZUL | 
| MentorBit | Pulsador Digital (PullUP) | PULSADOR_PULLUP_DIGITAL |
| MentorBit | Pulsador Digital (PullDOWN) | PULSADOR_PULLDOWN_DIGITAL |
| MentorBit | Pulsador Analógico (PullUP) | PULSADOR_PULLUP_ANALOGICO |
| MentorBit | Pulsador Analógico (PullDOWN) | PULSADOR_PULLDOWN_ANALOGICO |
| MentorBit | Zumbador | ZUMBADOR |
| MentorBit | Potenciómetro | POTENCIOMETRO |
| MentorBitSensores | Fotorresistencia | LDR |
| MentorBitSensores | Sensor de temperatura | DS18B20 |
| MentorBitMotores | Servomotor 1 | SERVOMOTOR_1 |
| MentorBitMotores | Servomotor 2 | SERVOMOTOR_2 |
| MentorBitMotores | Motor DC (Enable) | MOTOR_DC_EN |
| MentorBitMotores | Motor DC (Entrada 1) | MOTOR_DC_IN_1 |
| MentorBitMotores | Motor DC (Entrada 2) | MOTOR_DC_IN_2 |
| MentorBitMotores | Motor Paso a Paso (Bobina 1) | MOTOR_PAP_IN_1 |
| MentorBitMotores | Motor Paso a Paso (Bobina 2) | MOTOR_PAP_IN_2 |
| MentorBitMotores | Motor Paso a Paso (Bobina 3) | MOTOR_PAP_IN_3 |
| MentorBitMotores | Motor Paso a Paso (Bobina 4) | MOTOR_PAP_IN_4 |
| MentorBitPantallas | Pantalla LCD | lcd |
| MentorBitPantallas | Pantalla OLED | oled |
| MentorBitDataLogger | Pin selector de tarjeta SD | SD_CHIP_SELECT |
| MentorBitDataLogger | Reloj en Tiempo Real (RTC, Real Time Clock) | rtc |
| MentorBitPuertos | Pin digital Y del Puerto X (del 0 al 6) | PUERTO_X_DIGITAL_Y |
| MentorBitPuertos | Pin analógico Y del Puerto X (del 0 al 2) | PUERTO_X_ANALOG_Y |

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

El constructor de la clase provee una instancia de la clase MentorBit con los pines de conexión de los elementos básicos de la placa y algunos métodos para utilizarlos.
* LED de colores

* LED RGB

* Pulsadores

*  Zumbador

*  Potenciómetro

* `` void encenderLED(uint8_t led) ``
Enciende el diodo LED indicado como parámetro del método.

* `` void apagarLED(uint8_t led) ``
Apaga el diodo LED indicado como parámetro del método.

* `` void encenderRGB(uint8_t rojo, uint8_t verde, uint8_t azul) ``
Pone el LED RGB en los tonos e intensidades definidas para el color indicado como parámetro del método.

* `` void apagarRGB() ``
Apaga el LED RGB por completo.

* `` void generarTono(uint16_t frecuencia, uint8_t duracion) ``
Genera un tono de frecuencia y duración determiadas según los parámetros dados al método.

* `` bool obtenerLecturaPulsador(uint8_t pulsador) ``
Devuelve la lectura digital o analógica obtenida de los puertos donde se encuentran conectados los pulsadores según el indicado como parámetro del método.

* `` uint16_t obtenerLecturaPotenciometro() ``
Devuelve la lectura analógica obtenida del puerto donde se encuentra conectado el Potenciómetro.

## MentorBitDataLogger

Librería del módulo de DataLogger (SD y RTC) para MentorBit Arduino. En ella se declaran los atributos y métodos para la clase MentorBitDataLogger,
El constructor de la clase devuelve una instancia de la clase MentorBitDataLogger que provee los pines y métodos necesarios para controlar la tarjeta SD y el RTC en el MentorBit.

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
* `` void inicializarServo(uint8_t servomotor) ``

Una vez inicializado el Servo se provee de tres funciones que permiten manejar los diferentes motores.
* `` void moverServo(uint8_t servomotor, uint16_t grados) ``
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
*  LDR

*  DS18B20

``uint8_t  obtenerLecturaLDR()``
Devuelve un valor entero con la lectura obtenida de la fotorresistencia

``float  obtenerLecturaDS18B20()``
Devuelve un valor decimal con la lectura en Centígrados obtenida en el pin donde se encuentra conectado el DS18B20.
