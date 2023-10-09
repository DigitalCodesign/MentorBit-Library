# Librería de Entrenador Arduino

Esta librería está construida por Digital Codesign para utilizar junto con el kit educacional "Entrenador Arduino". La librería se compone de ocho clases diferentes que permiten utilizar las diferentes funcionalidades del Entrenador a través de varias funciones y ejemplos.

Puedes encontrar nuestro Kit de Entrenador Arduino y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)


Autor: **Kevin Rosa** - kevin.ingenieria@digitalcodesign.com
Fecha de última modificación: *6/10/2023*

![My Skills](https://skills.thijs.gg/icons?i=c,cpp,github&theme=light)

# Modo de empleo
Cuando tengas la librería instalada, debes incluir la librería al comienzo de tu sketch, antes del setup, con la siguiente línea:

   ``#include  "Entrenador.h"``

### Constructor

Crea una instancia de la clase con el nombre que más te guste, nosotros usaremos en este caso "miEntrenador". Al constructor del entrenador solo debemos indicarle el nombre de la instancia (No olvidar el ;)

``Entrenador miEntrenador;``

Ahora podemos emplear las propiedades y métodos de nuestro objeto miEntrenador. La librería ya incluye la declaración de todos los pines y funciones necesarias para utilizar el kit.

### Elementos del Entrenador 
Hay una serie de elementos que vienen incluidos en el Entrenador como Leds, Pulsadores, etcétera. Para referirnos a cada uno de ellos en nuestro código debemos emplear el nombre que se le ha dado en la librería. Podemos mirar la siguiente tabla para ver la relación entre los elementos y sus nombres de referencia.
|Elemento  |Nombre de ref.  |
|--|--|
| Led de color Rojo | ledRojo |
|Led de color Verde |ledVerde |
|Led de color Azul | ledAzul|
|RGB elemento Rojo |rgbRojo |
|RGB elemento Verde |rgbVerde |
|RGB elemento Azul |rgbAzul | 
|Pulsador Digital (PullUP) | pulsadorPullUpDigital|
|Pulsador Digital (PullDOWN) |pulsadorPullDownDigital |
|Pulsador Analógico (PullUP) |pulsadorPullUpAnalogico  |
|Pulsador Analógico (PullDOWN) | pulsadorPullDownAnalogico |
|Zumbador |zumbador  |
|Potenciómetro |potenciometro |

### Ejemplos
Dispones de ejemplos de diferentes dificultades para ir probando y experimentando con los distintos componentes del Entrenador (LEDs, pulsadores, zumbador, etc.). Aquí tienes una lista con todos los que hay y qué puedes hacer con ellos:

|Ejemplo |  Descripción  |
|--|--|
| LedDeColores | Encendido secuencial de los LEDs |
| LedRGB |Encendido secuencial y combinado del RGB |   
| Potenciometro |Se toman lecturas del potenciómetro |    
| PulsadoresAnalógicos | Se captura el input analógico del pulsador |    
| PulsadoresDigitales | Se captura el input digital del pulsador |   
| Zumbadores | Generación de tonos con el zumbador. |
| RTC | Establecer la hora manualmente y automáticamente  | 
| TarjetaSD | Escribir y leer sobre un archivo de la tarjeta.  |
| Display7Segments | Muestra varios valores en el display|
|  MotorDC |  Controla el motor de corriente continua |
| MotorPasoAPaso | Controla el motor Paso a Paso |
| Servomotor | Controla el servomotor |
| LCD |Muestra por la pantalla el mensaje "Hello, world!". |
|OLED |Muestra por la pantalla el icono por defecto. |
|Puerto_1 | Encendido secuencial de los pines del puerto 1 |
|Puerto_2 | Encendido secuencial de los pines del puerto 2 |
|Puerto_3  |  Encendido secuencial de los pines del puerto 3|
|DHT|  Recogida de la información del sensor y volcado en Serial |
|DS18B20 | Recogida de temperatura del sensor |
|LDR| Lectura de la fotorresistencia |
|MQ| Encendido de un LED utilizando la medida del MQ |
|Ultrasonidos| Recogida de la distancia entre objecto y sensor |


# Ficheros

En esta versión se cuenta con quince archivos principales en la librería : 
- Entrenador.cpp
- Entrenador.h
- EntrenadorComunicaciones.h
- EntrenadorDataLogger.cpp
- EntrenadorDataLogger.h
- EntrenadorDisplay.cpp
- EntrenadorDisplay.h
- EntrenadorMotores.cpp
- EntrenadorMotores.h
- EntrenadorPantallas.cpp
- EntrenadorPantallas.h
- EntrenadorPuertos.cpp
- EntrenadorPuertos.h
- EntrenadorSensores.cpp
- EntrenadorSensores.h

## Entrenador

Librería base para Entrenador Arduino. Contiene la definición de la clase base Entrenador, que es referida al Entrenador compatible con Arduino.

El constructor de la clase provee una instancia de la clase Entrenador con los pines de conexión de los elementos básicos de la placa.
* LED de colores

* LED RGB

* Pulsadores

*  Zumbador

*  Potenciómetro

## EntrenadorComunicaciones

Contiene la declaración de atributos y métodos para la clase EntrenadorComunicaciones, que es referida al Entrenador compatible con Arduino y su módulo de comunicaciones.
* Serial

* I2C

* SPI

* HC-06

* ESP01

## EntrenadorDataLogger

Librería del módulo de DataLogger (SD y RTC) para Entrenador Arduino. En ella se declaran los atributos y métodos para la clase EntrenadorDataLogger,
El constructor de la clase devuelve una instancia de la clase EntrenadorDataLogger que provee los pines y métodos necesarios para controlar la tarjeta SD y el RTC en el Entrenador.

``EntrenadorDataLogger() {
	chipSelectSD = PIN_A6;
}``

Cuenta con siete funciones que nos permiten un mejor manejo de la información.
* `` String leerDeArchivo(String nombre) ``
* `` boolean escribirEnArchivo(String nombre,  String mensaje) ``
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
 

## EntrenadorDisplay

Librería del módulo de Display para Entrenador Arduino. En ella se define de la clase EntrenadorDisplay, referida al Entrenador compatible con Arduino y el módulo de display 7 segmentos.

Incluido su constructor e inicializador cuenta con el métodos imprimir:
* `` EntrenadorDisplay() ``
Devuelve una instancia de la clase EntrenadorDisplay que provee las direcciones y métodos necesarios para controlar el display 7 segmentos integrado en el Entrenador

* `` void inicializarDisplay() ``

El método `` void imprimir(X valor) ``está sobrecargado para funcionar con los siguientes tipos de datos
* int
* double
* char
* string



## EntrenadorMotores

Librería del módulo Motores para Entrenador Arduino. Definición de la clase EntrenadorMotores, referida al Entrenador compatible con Arduino y el módulo de Motores.
* `` EntrenadorMotores() ``
* `` void inicializarServo() ``

Una vez inicializado el Servo se provee de tres funciones que permiten manejar el motor
* `` void moverServo(uint16_t grados) ``
* `` void moverMotorDC(uint8_t velocidad,  uint8_t direccion) ``
* `` void moverMotorPP(uint16_t pasos,  uint8_t direccion) ``


## EntrenadorPantallas

Definición de la clase EntrenadorPantallas, referida al Entrenador compatible con Arduino y el módulo de pantallas.
* `` EntrenadorPantallas() ``
Devuelve una instancia de la clase EntrenadorPantallas que provee las direcciones de conexión de los pantallas de la placa y un objeto para utilizarlas.

* `` void inicializarLCD() ``
* `` void inicializarOLED() ``

## EntrenadorPuertos

Librería de los puertos genéricos para Entrenador Arduino. Definición de la clase base EntrenadorPuertos, que hace referencia a los diferentes puertos que forma parte del Entrenador compatible con Arduino de forma genérica.

La clase cuenta con un constructor ``EntrenadorPuertos()`` que devuelve una instancia de la clase EntrenadorPuertos que provee los pines de conexión de los conectores de los puertos.
*  Puerto genérico 1
*  Puerto genérico 2
*  Puerto genérico 3
Cada uno compuesto de seis puertos digitales y dos analógicos.

## EntrenadorSensores

Librería del módulo Sensores para Entrenador Arduino. Definición de la clase EntrenadorSensores, referida al Entrenador compatible con Arduino y el módulo de sensores.

``EntrenadorSensores()``
 Devuelve una instancia de la clase EntrenadorSensores que provee los pines de conexión de los sensores de la placa y los puertos correspondientes. También provee de los métodos necesarios para obtener las lecturas de cada sensor de manera sencilla.
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
