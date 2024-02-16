/*
 * EntrenadorDataLogger.h - Librería del módulo de DataLogger (SD y RTC) para Entrenador Arduino
 *
 * Creado el 18/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorDataLogger,
 * referida al Entrenador compatible con Arduino y el módulo de SD y RTC.
 * 
 */

#include "EntrenadorDataLogger.h"

/*
 * Constructor de la clase para el módulo de SD y RTC del Entrenador.
 * 
 * Devuelve una instancia de la clase EntrenadorDataLogger que provee los
 * pines y métodos necesarios para controlar la tarjeta SD y el RTC en el Entrenador.
 */
EntrenadorDataLogger::EntrenadorDataLogger()
{

    chipSelectSD = PIN_A6;

}

/*
 * Función para inicializar el RTC.
 * 
 * Devuelve un booleano, true si consigue inicializar correctamente
 * y false si no es capaz de hacerlo.
 */
boolean EntrenadorDataLogger::inicializarRTC()
{

    if(!EntrenadorDataLogger::rtc.begin())
    {

        return false;

    }

    return true;

}

/*
 * Función para ajustar la hora del RTC a la hora dada.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorDataLogger::ajustarHoraRTC(
    uint16_t anyo,
    uint8_t mes,
    uint8_t dia,
    uint8_t hora=0,
    uint8_t minuto=0,
    uint8_t segundo=0
)
{

    EntrenadorDataLogger::rtc.adjust(DateTime(anyo, mes, dia, hora, minuto, segundo));

}

/*
 * Función para ajustar la hora del RTC por defecto a la hora del sistema.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorDataLogger::ajustarHoraRTC()
{

    EntrenadorDataLogger::rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

/*
 * Función que devuelve la hora actual del RTC.
 * 
 * Hora actual en formato cadena de texto.
 */
String EntrenadorDataLogger::obtenerHoraRTC()
{

    DateTime actualTime = EntrenadorDataLogger::rtc.now();

    return String(actualTime.timestamp(DateTime::TIMESTAMP_FULL));

}

/*
 * Función para inicializar la tarjeta SD.
 * 
 * Devuelve un booleano, true si consigue inicializar correctamente
 * y false si no es capaz de hacerlo.
 */
boolean EntrenadorDataLogger::inicializarSD()
{

    if(!SD.begin(EntrenadorDataLogger::chipSelectSD))
    {

        return false;

    }

    return true;

}

/*
 * Función para escribir en el archivo de nombre dado el mensaje dado.
 * 
 * Devuelve un booleano, true si consigue realizar la escritura correctamente
 * y false si no es capaz de hacerlo.
 */
boolean EntrenadorDataLogger::escribirEnArchivo(String nombre, String mensaje)
{

    EntrenadorDataLogger::_dataFile = SD.open(nombre, FILE_WRITE);

    if(EntrenadorDataLogger::_dataFile)
    {

        EntrenadorDataLogger::_dataFile.println(mensaje);
        EntrenadorDataLogger::_dataFile.close();

        return true;

    }

    return false;

}

/*
 * Función para leer del archivo de nombre dado todo el contenido.
 * 
 * Devuelve una cadena de texto con el contenido del archivo o una cadena vacía
 * si no es capaz de realizar la lectura.
 */
String EntrenadorDataLogger::leerDeArchivo(String nombre)
{

    String dataFromFile = "None";
    EntrenadorDataLogger::_dataFile = SD.open(nombre, FILE_READ);

    if(EntrenadorDataLogger::_dataFile)
    {

        char incomingChar = NULL;
        dataFromFile = "";
        while(EntrenadorDataLogger::_dataFile.available())
        {

            incomingChar = EntrenadorDataLogger::_dataFile.read();
            dataFromFile += incomingChar;

        }

        EntrenadorDataLogger::_dataFile.close();

    }

    return dataFromFile;

}
