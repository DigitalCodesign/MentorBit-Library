/*
 * MentorBitSensores.cpp - Librería del módulo Sensores para MentorBit Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase MentorBitSensores,
 * referida al MentorBit compatible con Arduino y el módulo de sensores.
 */

#include "MentorBitSensores.h"

/*
 * Constructor de la clase para el módulo de Sensores del MentorBit.
 * 
 * Devuelve una instancia de la clase MentorBitSensores que provee los pines
 * de conexión de los sensores de la placa y los puertos correspondientes.
 * También provee de los métodos necesarios para obtener las lecturas de cada
 * sensor de manera sencilla.
 * 
 * -> DS18B20
 * -> DHT
 * -> LDR
 * -> HC-SR04
 */
MentorBitSensores::MentorBitSensores() : ds18b20Wire(DS18B20), _first_try(true) {}

/*
 * Función para obtener la medida de la fotorresistencia.
 * 
 * Devuelve un valor entero con la lectura obtenida en el pin donde se
 * encuentra conectado el LDR.
 */
uint16_t MentorBitSensores::obtenerLecturaLDR()
{

    return analogRead(LDR);

}

/*
 * Función para obtener la medida de temperatura del DS18B20.
 * 
 * Devuelve un valor decimal con la lectura en Centígrados obtenida en el
 * pin donde se encuentra conectado el DS18B20.
 */
float MentorBitSensores::obtenerLecturaDS18B20()
{

    int16_t temp;

    ds18b20Wire.reset();
    ds18b20Wire.write(0xCC);
    ds18b20Wire.write(0x44);
    ds18b20Wire.reset();
    ds18b20Wire.write(0xCC);
    ds18b20Wire.write(0xBE);
    ds18b20Wire.read_bytes((uint8_t*) &temp, sizeof(temp));

    return (temp * 0.0625);

}
