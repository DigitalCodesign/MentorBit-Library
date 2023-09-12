/*
 * EntrenadorSensores.cpp - Librería del módulo Sensores para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase EntrenadorSensores,
 * referida al Entrenador compatible con Arduino y el módulo de sensores.
 */

#include "libraries/DHT_sensor_library/DHT.cpp"
#include "libraries/DallasTemperature/DallasTemperature.cpp"
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
    : myDHT(24, DHT11)
    , DS18B20(new OneWire(27))
{

    LDRpin = PIN_A1;
    MQpin = PIN_A4;
    DHTpin = 24;
    DS18B20pin = 9;
    HCSRecho = 2;
    HCSRtrigger = 26;

    myDHT.begin(55);
    DS18B20.begin();

    pinMode(LDRpin, INPUT);
    pinMode(MQpin, INPUT);
    pinMode(DHTpin, INPUT);
    pinMode(DS18B20pin, INPUT);
    pinMode(HCSRecho, INPUT);
    pinMode(HCSRtrigger, OUTPUT);

}

/*
 * Función para obtener la medida de la fotorresistencia.
 * 
 * Devuelve un valor entero con la lectura obtenida en el pin donde se
 * encuentra conectado el LDR.
 */
uint8_t EntrenadorSensores::obtenerLecturaLDR()
{

    return analogRead(LDRpin);

}

/*
 * Función para obtener la medida del sensor MQ.
 * 
 * Devuelve un valor entero con la lectura obtenida en el pin donde se
 * encuentra conectado el MQ.
 */
uint8_t EntrenadorSensores::obtenerLecturaMQ()
{

    return analogRead(MQpin);

}

/*
 * Función para obtener la medida de temperatura del DHT.
 * 
 * Devuelve un valor decimal con la lectura en Centígrados obtenida en el
 * pin donde se encuentra conectado el DHT.
 */
float EntrenadorSensores::obtenerTemperaturaDHT()
{

    return myDHT.readTemperature();

}

/*
 * Función para obtener la medida de humedad del DHT.
 * 
 * Devuelve un valor decimal con la lectura en tanto por ciento obtenida
 * en el pin donde se encuentra conectado el DHT.
 */
float EntrenadorSensores::obtenerHumedadDHT()
{

    return myDHT.readHumidity();

}

/*
 * Función para obtener la medida de temperatura del DS18B20.
 * 
 * Devuelve un valor decimal con la lectura en Centígrados obtenida en el
 * pin donde se encuentra conectado el DS18B20.
 */
float EntrenadorSensores::obtenerTemperaturaDS18B20()
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
uint16_t EntrenadorSensores::obtenerDistanciaUlrasonidos()
{

    digitalWrite(HCSRtrigger, LOW);
    delayMicroseconds(4);
    digitalWrite(HCSRtrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(HCSRtrigger, LOW);

    long duration = pulseIn(HCSRecho, HIGH);
    long distance = duration * 10 / 292 / 2;

    return distance;

}
