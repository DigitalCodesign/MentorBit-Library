/*
 * MentorBitSensores.h - Librería del módulo de Sensores para MentorBit Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase MentorBitSensores,
 * referida al MentorBit compatible con Arduino y el módulo de sensores.
 * 
 * -> DS18B20
 * -> LDR
 */

#ifndef MentorBitSensores_h
#define MentorBitSensores_h

    #include "Arduino.h"
    #include "OneWire.h"

    class MentorBitSensores
    {

        public:

            static const uint8_t LDR = PIN_A1;
            static const uint8_t DS18B20 = 27;

            MentorBitSensores();

            uint16_t obtenerLecturaLDR();
            float obtenerLecturaDS18B20();

        private:

            OneWire ds18b20Wire;

    };

#endif
