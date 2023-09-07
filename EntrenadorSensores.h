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

            uint8_t obtenerLuzLDR();
            float obtenerTemperaturaDHT();
            float obtenerHumedadDHT();
            float obtenerTemperaturaDS18B20();
            uint16_t obtenerDistanciaUlrasonidos();

            // FALTA EL MQ
            uint8_t LDRpin;
            uint8_t DHTpin;
            uint8_t DS18B20pin;
            uint8_t HCSRecho;
            uint8_t HCSRtrigger;

        private:

            DHT DHT11;
            DallasTemperature DS18B20;
            OneWire _oneWireObject;

            EntrenadorSensores(uint8_t DHTpin) : DHT11(DHTpin, DHT11) {}
            EntrenadorSensores(uint8_t DS18B20pin) : _oneWireObject(DS18B20pin) {}
            EntrenadorSensores(OneWire) : DS18B20(OneWire) {}

    };

#endif
