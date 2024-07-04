/*
 * MentorBitSensores.h - Librería del módulo de Sensores para MentorBit Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase MentorBitSensores,
 * referida al MentorBit compatible con Arduino y el módulo de sensores.
 * 
 * -> DHT
 * -> MQ
 * -> HC-SR04
 * -> DS18B20
 * -> LDR
 */

#ifndef MentorBitSensores_h
#define MentorBitSensores_h

    #include "Arduino.h"
    #include "DHT.h"
    #include "OneWire.h"
    #include "DallasTemperature.h"

    class MentorBitSensores
    {

        public:

            MentorBitSensores();

            uint8_t obtenerLecturaLDR();
            uint8_t obtenerLecturaMQ();
            float obtenerTemperaturaDHT();
            float obtenerHumedadDHT();
            float obtenerTemperaturaDS18B20();
            uint16_t obtenerDistanciaUlrasonidos();

            uint8_t ldr;
            uint8_t mq;
            uint8_t dht;
            uint8_t ds18b20;
            uint8_t ultrasonidosEcho;
            uint8_t ultrasonidosTrigger;

        private:

            DHT myDHT;
            DallasTemperature DS18B20;

    };

#endif
