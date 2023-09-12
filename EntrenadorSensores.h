/*
 * EntrenadorSensores.h - Librería del módulo de Sensores para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorSensores,
 * referida al Entrenador compatible con Arduino y el módulo de sensores.
 * 
 * -> DHT
 * -> MQ
 * -> HC-SR04
 * -> DS18B20
 * -> LDR
 */

#ifndef EntrenadorSensores_h
#define EntrenadorSensores_h

    #include "Arduino.h"
    #include "libraries/DHT_sensor_library/DHT.h"
    #include "libraries/OneWire/OneWire.h"
    #include "libraries/DallasTemperature/DallasTemperature.h"

    class EntrenadorSensores
    {

        public:

            EntrenadorSensores();

            uint8_t obtenerLecturaLDR();
            uint8_t obtenerLecturaMQ();
            float obtenerTemperaturaDHT();
            float obtenerHumedadDHT();
            float obtenerTemperaturaDS18B20();
            uint16_t obtenerDistanciaUlrasonidos();

            uint8_t LDRpin;
            uint8_t MQpin;
            uint8_t DHTpin;
            uint8_t DS18B20pin;
            uint8_t HCSRecho;
            uint8_t HCSRtrigger;

        private:

            DHT myDHT;
            DallasTemperature DS18B20;

    };

#endif
