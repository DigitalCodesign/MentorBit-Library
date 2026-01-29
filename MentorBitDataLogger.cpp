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
MentorBitDataLogger::MentorBitDataLogger() : _rtc_address(0x68) {}

// --- Métodos específicos de la Tarjeta SD

/*
 * Función para inicializar la tarjeta SD.
 * 
 * Devuelve un booleano, true si consigue inicializar correctamente
 * y false si no es capaz de hacerlo.
 */
boolean MentorBitDataLogger::inicializarSD()
{

    if(!SD.begin(SD_CHIP_SELECT))
        return false;

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

    _data_file = SD.open(nombre, FILE_WRITE);

    if(_data_file)
    {
        _data_file.println(mensaje);
        _data_file.close();
        return true;
    } else {
        return false;
    }

}

/*
 * Función para leer del archivo de nombre dado todo el contenido.
 * 
 * Devuelve una cadena de texto con el contenido del archivo o una cadena vacía
 * si no es capaz de realizar la lectura.
 */
String MentorBitDataLogger::leerDeArchivo(String nombre)
{

    String contenido = "";
    _data_file = SD.open(nombre, FILE_READ);

    if(_data_file)
    {
        while(_data_file.available())
            contenido += (char)_data_file.read();

        _data_file.close();

    }

    return contenido;

}

/*
 * Función para combinar la lectura del RTC con la escritura en la SD para guardar un LOG.
 * 
 * Devuelve un booleano, true si consigue guardar correctamente
 * y false si no es capaz de hacerlo.
 */
boolean MentorBitDataLogger::escribirLog(String nombre_archivo, String mensaje)
{

    String time_stamp = obtenerHoraRTC("[DD/MM/YYYY hh:mm:ss]");
    String log = time_stamp + " " + mensaje;
    return escribirEnArchivo(nombre_archivo, log);

}

// --- Métodos específicos del Reloj en Tiempo Real

/*
 * Función para inicializar el RTC.
 * 
 * Devuelve un booleano, true si consigue inicializar correctamente
 * y false si no es capaz de hacerlo.
 */
boolean MentorBitDataLogger::inicializarRTC()
{

    Wire.begin();
    Wire.beginTransmission(_rtc_address);
    if (Wire.endTransmission() != 0) return false;

    if (!rtcFuncionando())
    {
        Wire.beginTransmission(_rtc_address);
        Wire.write(0x00);
        Wire.write(0x00);
        Wire.endTransmission();
    }

    return true;

}

/*
 * Función para ajustar la hora del RTC a la hora dada.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDataLogger::ajustarHoraRTC(uint16_t anyo, uint8_t mes, uint8_t dia, uint8_t hora, uint8_t minuto, uint8_t segundo)
{

    Wire.beginTransmission(_rtc_address);
    Wire.write(0x00);
    Wire.write(decToBcd(segundo));
    Wire.write(decToBcd(minuto));
    Wire.write(decToBcd(hora));
    Wire.write(decToBcd(0));
    Wire.write(decToBcd(dia));
    Wire.write(decToBcd(mes));
    Wire.write(decToBcd(anyo - 2000));
    Wire.endTransmission();

}

/*
 * Función para ajustar la hora del RTC por defecto a la hora del sistema.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDataLogger::ajustarHoraRTC()
{

    const char* months = "JanFebMarAprMayJunJulAugSepOctNovDec";
    char temp_month[4];

    temp_month[0] = __DATE__[0];
    temp_month[1] = __DATE__[1];
    temp_month[2] = __DATE__[2];
    temp_month[3] = 0;

    uint8_t mes = 0;
    for (int i = 0 ; i < 12 ; i++)
    {
        if (strncmp(months + (i * 3), temp_month, 3) == 0)
        {
            mes = i + 1;
            break;
        }
    }

    uint8_t dia = atoi(__DATE__ + 4);
    uint8_t anyo = atoi(__DATE__ + 7);
    uint8_t hora = atoi(__TIME__);
    uint8_t minuto = atoi(__TIME__ + 3);
    uint8_t segundo = atoi(__TIME__ + 6);

    ajustarHoraRTC(anyo, mes, dia, hora, minuto, segundo);

}

/*
 * Función que devuelve la hora actual del RTC.
 * 
 * Hora actual en formato cadena de texto.
 */
String MentorBitDataLogger::obtenerHoraRTC(String formato)
{

    _leerRTC();

    String s_hh = (_hh < 10 ? "0" : "") + String(_hh);
    String s_mm = (_mm < 10 ? "0" : "") + String(_mm);
    String s_ss = (_ss < 10 ? "0" : "") + String(_ss);
    String s_DD = (_d < 10 ? "0" : "") + String(_d);
    String s_MM = (_m < 10 ? "0" : "") + String(_m);
    String s_YYYY = String(_y);

    formato.replace("hh", s_hh);
    formato.replace("mm", s_mm);
    formato.replace("ss", s_ss);
    formato.replace("DD", s_DD);
    formato.replace("MM", s_MM);
    formato.replace("YYYY", s_YYYY);

    return formato;

}

/**
 * Función para comprobar si el reloj está caminando.
 * 
 * Devuelve true si está funcionando, false en caso contrario.
 */
boolean MentorBitDataLogger::rtcFuncionando()
{

    Wire.beginTransmission(_rtc_address);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.requestFrom(_rtc_address, 1);
    uint8_t ss = Wire.read();

    return !(ss >> 7);

}

// --- Métodos extra (NVRAM)

/*
 * Función para almacenar un valor en la memoria interna del RTC.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDataLogger::guardarDato(uint8_t direccion, uint8_t dato)
{

    if (direccion > 55) return;

    Wire.beginTransmission(_rtc_address);
    Wire.write(0x08 + direccion);
    Wire.write(dato);
    Wire.endTransmission();

}

/**
 * Función para recuperar un valor de la memoria interna del RTC.
 * 
 * Devuelve el dato recuperado.
 */
uint8_t MentorBitDataLogger::leerDato(uint8_t direccion)
{

    if (direccion > 55) return;

    Wire.beginTransmission(_rtc_address);
    Wire.write(0x08 + direccion);
    Wire.endTransmission();

    Wire.requestFrom(_rtc_address, 1);
    return Wire.read();

}

// --- Métodos privados

uint8_t MentorBitDataLogger::bcdToDec(uint8_t valor)
{

    return ( (valor / 16 * 10) + (valor % 16) );

}

uint8_t MentorBitDataLogger::decToBcd(uint8_t valor)
{

    return ( (valor / 10 * 16) + (valor % 10) );

}

void MentorBitDataLogger::_leerRTC()
{

    Wire.beginTransmission(_rtc_address);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.requestFrom(_rtc_address, 7);

    _ss = bcdToDec(Wire.read() & 0x7F);
    _mm = bcdToDec(Wire.read());
    _hh = bcdToDec(Wire.read() & 0x3F);
    Wire.read();
    _d = bcdToDec(Wire.read());
    _m = bcdToDec(Wire.read());
    _y = bcdToDec(Wire.read()) + 2000;

}
