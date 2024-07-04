/*
 * MentorBitDataLogger.h - Librería del módulo de DataLogger (SD y RTC) para MentorBit Arduino
 *
 * Creado el 18/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase MentorBitDataLogger,
 * referida al MentorBit compatible con Arduino y el módulo de SD y RTC.
 * 
 */

#include "MentorBitDataLogger.h"

/*
 * Constructor de la clase para el módulo de SD y RTC del MentorBit.
 * 
 * Devuelve una instancia de la clase MentorBitDataLogger que provee los
 * pines y métodos necesarios para controlar la tarjeta SD y el RTC en el MentorBit.
 */
MentorBitDataLogger::MentorBitDataLogger()
{

    chipSelectSD = PIN_A6;

}

/*
 * Función para inicializar el RTC.
 * 
 * Devuelve un booleano, true si consigue inicializar correctamente
 * y false si no es capaz de hacerlo.
 */
boolean MentorBitDataLogger::inicializarRTC()
{

    if(!MentorBitDataLogger::rtc.begin())
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
void MentorBitDataLogger::ajustarHoraRTC(
    uint16_t anyo,
    uint8_t mes,
    uint8_t dia,
    uint8_t hora=0,
    uint8_t minuto=0,
    uint8_t segundo=0
)
{

    MentorBitDataLogger::rtc.adjust(DateTime(anyo, mes, dia, hora, minuto, segundo));

}

/*
 * Función para ajustar la hora del RTC por defecto a la hora del sistema.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDataLogger::ajustarHoraRTC()
{

    MentorBitDataLogger::rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

/*
 * Función que devuelve la hora actual del RTC.
 * 
 * Hora actual en formato cadena de texto.
 */
String MentorBitDataLogger::obtenerHoraRTC()
{

    DateTime actualTime = MentorBitDataLogger::rtc.now();

    return String(actualTime.timestamp(DateTime::TIMESTAMP_FULL));

}

/*
 * Función para inicializar la tarjeta SD.
 * 
 * Devuelve un booleano, true si consigue inicializar correctamente
 * y false si no es capaz de hacerlo.
 */
boolean MentorBitDataLogger::inicializarSD()
{

    if(!SD.begin(MentorBitDataLogger::chipSelectSD))
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
boolean MentorBitDataLogger::escribirEnArchivo(String nombre, String mensaje)
{

    MentorBitDataLogger::_dataFile = SD.open(nombre, FILE_WRITE);

    if(MentorBitDataLogger::_dataFile)
    {

        MentorBitDataLogger::_dataFile.println(mensaje);
        MentorBitDataLogger::_dataFile.close();

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
String MentorBitDataLogger::leerDeArchivo(String nombre)
{

    String dataFromFile = "None";
    MentorBitDataLogger::_dataFile = SD.open(nombre, FILE_READ);

    if(MentorBitDataLogger::_dataFile)
    {

        char incomingChar = NULL;
        dataFromFile = "";
        while(MentorBitDataLogger::_dataFile.available())
        {

            incomingChar = MentorBitDataLogger::_dataFile.read();
            dataFromFile += incomingChar;

        }

        MentorBitDataLogger::_dataFile.close();

    }

    return dataFromFile;

}
