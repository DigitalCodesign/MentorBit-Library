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
MentorBitSensores::MentorBitSensores()
    : myDHT(24, DHT11)
    , DS18B20(new OneWire(27))
{

    ldr = PIN_A1;
    mq = PIN_A4;
    dht = 24;
    ds18b20 = 9;
    ultrasonidosEcho = 2;
    ultrasonidosTrigger = 26;

    myDHT.begin();
    DS18B20.begin();

    pinMode(ldr, INPUT);
    pinMode(mq, INPUT);
    pinMode(dht, INPUT);
    pinMode(ds18b20, INPUT);
    pinMode(ultrasonidosEcho, INPUT);
    pinMode(ultrasonidosTrigger, OUTPUT);

}

/*
 * Función para obtener la medida de la fotorresistencia.
 * 
 * Devuelve un valor entero con la lectura obtenida en el pin donde se
 * encuentra conectado el LDR.
 */
uint8_t MentorBitSensores::obtenerLecturaLDR()
{

    return analogRead(ldr);

}

/*
 * Función para obtener la medida del sensor MQ.
 * 
 * Devuelve un valor entero con la lectura obtenida en el pin donde se
 * encuentra conectado el MQ.
 */
uint8_t MentorBitSensores::obtenerLecturaMQ()
{

    return analogRead(mq);

}

/*
 * Función para obtener la medida de temperatura del DHT.
 * 
 * Devuelve un valor decimal con la lectura en Centígrados obtenida en el
 * pin donde se encuentra conectado el DHT.
 */
float MentorBitSensores::obtenerTemperaturaDHT()
{

    return myDHT.readTemperature();

}

/*
 * Función para obtener la medida de humedad del DHT.
 * 
 * Devuelve un valor decimal con la lectura en tanto por ciento obtenida
 * en el pin donde se encuentra conectado el DHT.
 */
float MentorBitSensores::obtenerHumedadDHT()
{

    return myDHT.readHumidity();

}

/*
 * Función para obtener la medida de temperatura del DS18B20.
 * 
 * Devuelve un valor decimal con la lectura en Centígrados obtenida en el
 * pin donde se encuentra conectado el DS18B20.
 */
float MentorBitSensores::obtenerTemperaturaDS18B20()
{

    DS18B20.requestTemperatures();
    return DS18B20.getTempCByIndex(0);

}

/*
 * Función para obtener la medida de distancia del HC-SR04.
 * 
 * Devuelve un valor entero con la lectura en Centímetros obtenida con
 * los pines donde se encuentra conectado el HC-SR04 (Ultrasonidos).
 */
uint16_t MentorBitSensores::obtenerDistanciaUlrasonidos()
{

    digitalWrite(ultrasonidosTrigger, LOW);
    delayMicroseconds(4);
    digitalWrite(ultrasonidosTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonidosTrigger, LOW);

    long duration = pulseIn(ultrasonidosEcho, HIGH);
    long distance = duration * 10 / 292 / 2;

    return distance;

}
