# Librería de MentorBit

Esta librería está construida por Digital Codesign para utilizar junto con el kit educacional "MentorBit". La librería se compone de varias clases diferentes que permiten utilizar las diferentes funcionalidades del MentorBit a través de varias funciones y ejemplos.

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo
Cuando tengas la librería instalada, debes incluir la librería al comienzo de tu sketch, antes del setup, con la siguiente línea:

   `#include "MentorBit.h"`

En función del módulo que quieras utilizar, deberás importarlo de la misma manera que en el ejemplo.

### Constructor

Crea una instancia de la clase con el nombre que más te guste, nosotros usaremos en este caso "miMentorBit". Al constructor del MentorBit solo debemos indicarle el nombre de la instancia (No olvidar el ;).

`MentorBit miMentorBit;`

Ahora podemos emplear las propiedades y métodos de nuestro objeto miMentorBit. La librería incluye varios módulos importables cuyo constructor coincidirá con el nombre del módulo.

### Elementos del MentorBit
Hay una serie de elementos que vienen incluidos en el MentorBit como LEDs, Pulsadores, etcétera. Para referirnos a cada uno de ellos en nuestro código debemos emplear el nombre que se le ha dado en la librería. Podemos mirar la siguiente tabla para ver la relación entre los elementos y sus nombres de referencia.

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
| MentorBitDataLogger | Reloj en Tiempo Real (RTC) | rtc |
| MentorBitPuertos | Pin digital Y del Puerto X (del 0 al 6) | PUERTO_X_DIGITAL_Y |
| MentorBitPuertos | Pin analógico Y del Puerto X (del 0 al 2) | PUERTO_X_ANALOG_Y |

### Ejemplos
Dispones de ejemplos de diferentes dificultades para ir probando y experimentando con los distintos componentes del MentorBit (LEDs, pulsadores, zumbador, etc.). Aquí tienes una lista con todos los que hay y qué puedes hacer con ellos:

| Ejemplo | Descripción |
|--|--|
| LedDeColores | Encendido secuencial de los LEDs |
| LedRGB | Encendido secuencial y combinado del RGB |   
| Potenciometro | Se toman lecturas del potenciómetro |    
| PulsadoresAnalogicos | Se captura el input analógico del pulsador |    
| PulsadoresDigitales | Se captura el input digital del pulsador |   
| Zumbador | Generación de tonos con el zumbador. |
| RTC | Establecer la hora manualmente y automáticamente | 
| TarjetaSD | Escribir y leer sobre un archivo de la tarjeta. |
| Display7Segments | Muestra varios valores en el display |
| MotorDC | Controla el motor de corriente continua |
| MotorPasoAPaso | Controla el motor Paso a Paso |
| Servomotor | Controla el servomotor |
| LCD | Muestra por la pantalla el mensaje "Hello, world!". |
| OLED | Muestra por la pantalla el icono por defecto. |
| DHT | Recogida de la información del sensor y volcado en Serial |
| DS18B20 | Recogida de temperatura del sensor |
| LDR | Lectura de la fotorresistencia |
| MQ | Encendido de un LED utilizando la medida del MQ |
| Ultrasonidos | Recogida de la distancia entre objeto y sensor |
| Puerto_1 | Encendido secuencial de los pines del puerto 1 |
| Puerto_2 | Encendido secuencial de los pines del puerto 2 |
| Puerto_3 | Encendido secuencial de los pines del puerto 3 |


# Ficheros

En esta versión se cuenta con dieciséis archivos principales en la librería: 
- MentorBit.cpp y MentorBit.h
- MentorBitDataLogger.cpp y MentorBitDataLogger.h
- MentorBitDisplay.cpp y MentorBitDisplay.h
- MentorBitMotores.cpp y MentorBitMotores.h
- MentorBitPantallas.cpp y MentorBitPantallas.h
- MentorBitPuertos.cpp y MentorBitPuertos.h
- MentorBitSensores.cpp y MentorBitSensores.h
- MentorPort.h

---

## MentorBit

Librería base para MentorBit Arduino. Contiene la definición de la clase base MentorBit, que es referida al MentorBit compatible con Arduino.

El constructor de la clase provee una instancia con los pines de conexión de los elementos básicos de la placa y métodos para utilizarlos:

* `void encenderLED(uint8_t led)` / `void apagarLED(uint8_t led)`: Enciende o apaga el diodo LED indicado.
* `void encenderRGB(uint8_t rojo, uint8_t verde, uint8_t azul)`: Pone el LED RGB en los tonos e intensidades (0-255) indicadas.
* `void apagarRGB()`: Apaga el LED RGB por completo.
* `void generarTono(uint16_t frecuencia, uint8_t duracion)`: Genera un tono con la frecuencia y duración dadas.
* `bool obtenerLecturaPulsador(uint8_t pulsador)`: Devuelve la lectura digital obtenida de los pulsadores.
* `uint16_t obtenerLecturaPotenciometro()`: Devuelve la lectura analógica (0-1023) del potenciómetro.

---

## MentorBitDataLogger

Librería del módulo de DataLogger (SD y RTC). Provee los métodos necesarios para controlar la tarjeta SD y el Reloj en Tiempo Real (RTC).

**Tarjeta SD:**
* `boolean inicializarSD()`: Inicializa la tarjeta SD y devuelve `true` si funciona correctamente.
* `String leerDeArchivo(String nombre)`: Lee y devuelve todo el contenido del archivo especificado.
* `boolean escribirEnArchivo(String nombre, String mensaje)`: Escribe un mensaje en el archivo indicado.
* `boolean escribirLog(String nombre_archivo, String mensaje)`: Combina la lectura del RTC con la escritura en la SD para guardar un log con formato `[DD/MM/YYYY hh:mm:ss] mensaje`.

**RTC (Reloj en Tiempo Real):**
* `boolean inicializarRTC()` / `boolean rtcFuncionando()`: Inicializa y comprueba el estado del RTC.
* `String obtenerHoraRTC(String formato="hh:mm:ss")`: Devuelve la hora actual. Permite especificar un formato (ej. "DD/MM/YYYY hh:mm:ss").
* `void ajustarHoraRTC()`: Ajusta la hora automáticamente a la hora de compilación del sistema.
* `void ajustarHoraRTC(uint16_t anyo, uint8_t mes, uint8_t dia, uint8_t hora, uint8_t minuto, uint8_t segundo=0)`: Ajuste manual del reloj.
* `void guardarDato(uint8_t direccion, uint8_t dato)` / `uint8_t leerDato(uint8_t direccion)`: Almacena y recupera valores (bytes) directamente en la memoria interna (NVRAM) del RTC (hasta 56 bytes).

---

## MentorBitDisplay

Librería del módulo de Display 7 Segmentos. 

* `void inicializarDisplay()`: Enciende y prepara el display I2C integrado.
* El método `void imprimir(X valor)` está sobrecargado para mostrar diferentes tipos de datos automáticamente:
  * Cadenas de texto (`String` o arreglos de caracteres).
  * Números enteros (`int`).
  * Números decimales (`double`), respetando la posición de la coma.

---

## MentorBitMotores

Librería para el control de actuadores cinéticos. Incluye constantes en el enumerador `Direccion` (PARADO, ATRAS, IZQUIERDA, ANTIHORARIO, ADELANTE, DERECHA, HORARIO) para facilitar la lectura del código.

**Servomotores:**
* `void inicializarServo(uint8_t servomotor)` / `void desconectarServo(uint8_t servomotor)`: Conecta o desconecta dinámicamente un servo.
* `void moverServo(uint8_t servomotor, uint16_t grados)`: Posiciona el servo en el ángulo deseado.

**Motor DC:**
* `void moverMotorDC(uint8_t velocidad, uint8_t direccion)`: Mueve el motor a la velocidad (0-255) y sentido indicado.
* `void pararMotorDC()`: Frena el motor de corriente continua por completo.

**Motor Paso a Paso (Stepper):**
* `void moverMotorPP(uint16_t pasos, uint8_t direccion)`: Mueve el motor paso a paso la cantidad indicada.
* `void moverMotorPP(uint16_t pasos, uint8_t direccion, uint8_t tiempo_entre_pasos)`: Permite un control más fino indicando el delay (en milisegundos) entre pasos.

---

## MentorBitPantallas

Control combinado de pantallas avanzadas. Incluye los objetos `lcd` (pantalla de 16x2 I2C) y `oled` (matriz de puntos).

**Inicialización:**
* `void inicializarLCD()`: Inicia la LCD con su respectiva retroiluminación.
* `void inicializarOLED()`: Inicia el display OLED.

**Métodos Avanzados para la LCD (`MentorBitLCD`):**
La LCD de MentorBit no solo permite usar comandos estándar de la librería `Print` (como `lcd.print("Hola");`), sino que incluye funciones gráficas y utilidades:
* `clear()` y `home()`: Limpian la pantalla y reinician la posición del cursor.
* `setCursor(uint8_t col, uint8_t row)`: Posiciona el texto.
* `backlight()` / `noBacklight()`: Enciende y apaga la luz de fondo.
* `imprimirCentrado(uint8_t fila, String texto)`: Limpia una fila específica y centra un texto automáticamente.
* `dibujarBarra(uint8_t fila, uint8_t porcentaje)`: Dibuja una barra de progreso visual (0 a 100%) en la línea elegida.
* `cargarIcono(IconoLCD icono, uint8_t ubicacion_memoria)`: Carga uno de los iconos predefinidos en la memoria (0-7) de la LCD. Los iconos disponibles incluyen: `CORAZON`, `SONRISA`, `BATERIA_BAJA/MEDIA/LLENA`, `TEMPERATURA`, `GOTA_AGUA`, `RELOJ`, `WIFI`, `CAMPANA`, `CHECK_OK`, `CRUZ_NOK`, y flechas.

---

## MentorBitPuertos y MentorPort

Librerías para la gestión de conectividad modular de pines de propósito general. 

El sistema cuenta con tres puertos genéricos compuestos de pines digitales y analógicos, más dos puertos específicos de módulos:
* `MentorBitPuertos()`: Constructor que prepara la interfaz.
* `void conectar(uint8_t port, MentorPort& module)`: Vincula a nivel de software un puerto físico con un objeto módulo que herede de `MentorPort`.

`MentorPort.h` es la clase base (interfaz virtual) para la creación de librerías de módulos de expansión, dotando a MentorBit de extensibilidad estandarizada.

---

## MentorBitSensores

Librería de recolección de variables del entorno físico del MentorBit.

* `uint16_t obtenerLecturaLDR()`: Devuelve un valor analógico (0-1023) correspondiente a la luz detectada por la fotorresistencia.
* `float obtenerLecturaDS18B20()`: Solicita y convierte la información del bus *OneWire*, devolviendo la lectura exacta de la temperatura en grados Centígrados.

## Recursos Adicionales

¿Quieres saber más sobre MentorBit o necesitas comprar uno? Aquí tienes algunos enlaces que te serán de utilidad:

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Manual de usuario del MentorBit](https://drive.google.com/file/d/1LihxjplzKxC2sLOBprXDpevP77DC8Yiv/view)
- [Modelo 3D de MentorBit en formato .STEP](https://drive.google.com/file/d/1vkdoFbuI6Grp2JLRS9rvaMw9hJ6F_ViC/view?usp=drive_link)
