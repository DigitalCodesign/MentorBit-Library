/*
 * EntrenadorSensores.cpp - Librería del módulo Sensores para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase EntrenadorSensores,
 * referida al Entrenador compatible con Arduino y el módulo de sensores.
 */

#include "EntrenadorSensores.h"

/*
 * Constructor de la clase para el módulo de Sensores del Entrenador.
 * 
 * Devuelve una instancia de la clase EntrenadorSensores que provee los pines
 * de conexión de los sensores de la placa y los puertos correspondientes.
 * También provee de los métodos necesarios para obtener las lecturas de cada
 * sensor de manera sencilla.
 * 
 * -> DS18B20
 * -> DHT
 * -> LDR
 * -> HC-SR04
 */
EntrenadorSensores::EntrenadorSensores()
{

    this->LDRpin = PIN_A1;
    this->DHTpin = 24;
    this->DS18B20pin = 9;
    this->HCSRecho = 2;
    this->HCSRtrigger = 26;

    this->DHT11.begin();
    this->DS18B20.begin();

    pinMode(this->LDRpin, INPUT);
    pinMode(this->DHTpin, INPUT);
    pinMode(this->DS18B20pin, INPUT);
    pinMode(this->HCSRecho, INPUT);
    pinMode(this->HCSRtrigger, OUTPUT);

}

/*
 * Función para obtener la medida de la fotorresistencia.
 * 
 * Devuelve un valor entero con la lectura obtenida en el pin donde se
 * encuentra conectado el LDR.
 */
uint8_t EntrenadorSensores::obtenerLuzLDR()
{

    return analogRead(this->LDR);

}

/*
 * Función para obtener la medida de temperatura del DHT.
 * 
 * Devuelve un valor decimal con la lectura en Centígrados obtenida en el
 * pin donde se encuentra conectado el DHT.
 */
float EntrenadorSensores::obtenerTemperaturaDHT()
{

    return this->DHT11.readTemperature();

}

/*
 * Función para obtener la medida de humedad del DHT.
 * 
 * Devuelve un valor decimal con la lectura en tanto por ciento obtenida
 * en el pin donde se encuentra conectado el DHT.
 */
float EntrenadorSensores::obtenerHumedadDHT()
{

    return this->DHT11.readHumidity();

}

/*
 * Función para obtener la medida de temperatura del DS18B20.
 * 
 * Devuelve un valor decimal con la lectura en Centígrados obtenida en el
 * pin donde se encuentra conectado el DS18B20.
 */
float EntrenadorSensores::obtenerTemperaturaDS18B20()
{

    this->DS18B20.requestTemperatures();
    return this->DS18B20.getTempCByIndex(0);

}

/*
 * Función para obtener la medida de distancia del HC-SR04.
 * 
 * Devuelve un valor entero con la lectura en Centímetros obtenida con
 * los pines donde se encuentra conectado el HC-SR04 (Ultrasonidos).
 */
uint16_t EntrenadorSensores::obtenerDistanciaUlrasonidos()
{

    digitalWrite(this->HCSRtrigger, LOW);
    delayMicroseconds(4);
    digitalWrite(this->HCSRtrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->HCSRtrigger, LOW);

    long duration = pulseIn(this->HCSRecho, HIGH);
    long distance = duration * 10 / 292 / 2;

    return distance;

}
