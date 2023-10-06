# Librería de Entrenador Arduino

Esta librería recopila los elementos necesarios para el correcto funcionamiento del entrenador de arduino. Tales como clases, atributos y funciones. La librería cuenta con ocho clases diferentes especificadas para abordar diferentes funcionalidades.   

Autor: **Kevin Rosa** - kevin.ingenieria@digitalcodesign.com
Fecha de última modificación: *6/10/2023*

![My Skills](https://skills.thijs.gg/icons?i=c,cpp,github&theme=light)

# Ficheros

En esta versión se cuenta con quince archivos principales en la librería : 
- Entrenador.cpp
- Entrenador.h
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

El constructor de la clase provee una instancia de la clase Entrenador con los pines de conexión de los elementos básicos de la placa:
* LED de colores

* LED RGB

* Pulsadores

*  Zumbador

*  Potenciómetro

## EntrenadorDataLogger

Librería del módulo de DataLogger (SD y RTC) para Entrenador Arduino. En ella se declaran los atributos y métodos para la clase EntrenadorDataLogger,
El constructor de la clase devuelve una instancia de la clase EntrenadorDataLogger que provee los pines y métodos necesarios para controlar la tarjeta SD y el RTC en el Entrenador.

Cuenta con siete funciones que nos permiten un mejor manejo de la información:

* `` String leerDeArchivo(String nombre) ``
Lee el contenido del archivo indicado y devuelve el contenido del archivo o una cadena vacía si no es capaz de realizar la lectura.

* `` boolean escribirEnArchivo(String nombre,  String mensaje) ``
Escribe en el archivo inficado el contenido deseado y devuelve **TRUE** si consigue realizar la escritura correctamente y **FALSE** si no es capaz de hacerlo.

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

Librería del módulo de Display para Entrenador Arduino. En ella se define la clase EntrenadorDisplay, referida al Entrenador compatible con Arduino y el módulo de display 7 segmentos.

Incluye su constructor e inicializador:

* `` EntrenadorDisplay() ``
Devuelve una instancia de la clase EntrenadorDisplay que provee las direcciones y métodos necesarios para controlar el display 7 segmentos integrado en el Entrenador

* `` void inicializarDisplay() ``
Inicializa el display 7 segmentos.

Y un método `` void imprimir(X valor) ``, que está sobrecargado para funcionar con los siguientes tipos de datos:
* int
* double
* char
* string



## EntrenadorMotores

Librería del módulo Motores para Entrenador Arduino. Definición de la clase EntrenadorMotores, referida al Entrenador compatible con Arduino y el módulo de Motores.
* `` EntrenadorMotores() ``
* `` void inicializarServo() ``

Una vez inicializado el Servo se proveen tres funciones que permiten manejar los diferentes motores:
* `` void moverServo(uint16_t grados) ``
* `` void moverMotorDC(uint8_t velocidad,  uint8_t direccion) ``
* `` void moverMotorPP(uint16_t pasos,  uint8_t direccion) ``


## EntrenadorPantallas

Definición de la clase EntrenadorPantallas, referida al Entrenador compatible con Arduino y el módulo de pantallas:
* `` EntrenadorPantallas() ``
Devuelve una instancia de la clase EntrenadorPantallas que provee las direcciones de conexión de los pantallas de la placa y un objeto para utilizarlas.

* `` void inicializarLCD() ``
Inicializa la pantalla LCD.

* `` void inicializarOLED() ``
Inicializa la pantalla OLED.

## EntrenadorPuertos

Librería de los puertos genéricos para Entrenador Arduino. Definición de la clase base EntrenadorPuertos, que hace referencia a los diferentes puertos de conexión genérica que forman parte del Entrenador compatible con Arduino.

La clase cuenta con un constructor ``EntrenadorPuertos()`` que devuelve una instancia de la clase EntrenadorPuertos que provee los pines de conexión de los conectores de los puertos:
*  Puerto genérico 1
*  Puerto genérico 2
*  Puerto genérico 3

Cada uno de los puertos está compuesto por seis puertos digitales de entrada/salida, de los cuales dos permiten generar una señal PWM, y dos entradas analógicas.

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
  Devuelve un valor decimal con la lectura de la temperatura en grados Centígrados obtenida en el pin donde se encuentra conectado el DHT.

``float obtenerHumedadDHT()``
Devuelve un valor decimal con la lectura correspondiente a la humedad relativa del ambiente en un formato de porcentaje obtenida en el pin donde se encuentra conectado el DHT.
  

``float  obtenerTemperaturaDS18B20()``
Devuelve un valor decimal con la lectura en grados Centígrados obtenida en el pin donde se encuentra conectado el DS18B20.

``uint16_t  obtenerDistanciaUlrasonidos()``
Devuelve un valor entero con la lectura en Centímetros obtenida con los pines donde se encuentra conectado el HC-SR04 (Ultrasonidos).