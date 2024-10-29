/*
 * MentorBitPuertos.h - Librería de los puertos genéricos para MentorBit Arduino
 *
 * Creado el 27/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase base MentorBitPuertos,
 * referida al MentorBit compatible con Arduino y sus puertos genéricos.
 * 
 * -> Puerto genérico 1
 * -> Puerto genérico 2
 * -> Puerto genérico 3
 */

#include "Arduino.h"

#ifndef MentorBitPuertos_h
#define MentorBitPuertos_h

    #include "MentorPort.h"

    class MentorBitPuertos
    {

        public:

            static const uint8_t PUERTO_MODULO_1 = 0x01;
            static const uint8_t PUERTO_MODULO_2 = 0x02;
            static const uint8_t PUERTO_GENERICO_1 = 0x03;
            static const uint8_t PUERTO_GENERICO_2 = 0x04;
            static const uint8_t PUERTO_GENERICO_3 = 0x05;

            static const uint8_t PUERTO_MODULO_1_ANALOGICO = PIN_A4;
            static const uint8_t PUERTO_MODULO_1_DIGITAL = 24;
            static const uint8_t PUERTO_MODULO_2_ANALOGICO = PIN_A7;
            static const uint8_t PUERTO_MODULO_2_DIGITAL = 26;

            static const uint8_t PUERTO_GENERICO_1_DIGITAL_1 = 35;
            static const uint8_t PUERTO_GENERICO_1_DIGITAL_2 = 36;
            static const uint8_t PUERTO_GENERICO_1_DIGITAL_3 = 37;
            static const uint8_t PUERTO_GENERICO_1_DIGITAL_4 = 38;
            static const uint8_t PUERTO_GENERICO_1_DIGITAL_5 = 3;
            static const uint8_t PUERTO_GENERICO_1_DIGITAL_6 = 2;
            static const uint8_t PUERTO_GENERICO_1_ANALOG_1 = PIN_A10;
            static const uint8_t PUERTO_GENERICO_1_ANALOG_2 = PIN_A11;

            static const uint8_t PUERTO_GENERICO_2_DIGITAL_1 = 39;
            static const uint8_t PUERTO_GENERICO_2_DIGITAL_2 = 40;
            static const uint8_t PUERTO_GENERICO_2_DIGITAL_3 = 41;
            static const uint8_t PUERTO_GENERICO_2_DIGITAL_4 = 42;
            static const uint8_t PUERTO_GENERICO_2_DIGITAL_5 = 13;
            static const uint8_t PUERTO_GENERICO_2_DIGITAL_6 = 44;
            static const uint8_t PUERTO_GENERICO_2_ANALOG_1 = PIN_A12;
            static const uint8_t PUERTO_GENERICO_2_ANALOG_2 = PIN_A13;

            static const uint8_t PUERTO_GENERICO_3_DIGITAL_1 = 43;
            static const uint8_t PUERTO_GENERICO_3_DIGITAL_2 = 47;
            static const uint8_t PUERTO_GENERICO_3_DIGITAL_3 = 48;
            static const uint8_t PUERTO_GENERICO_3_DIGITAL_4 = 49;
            static const uint8_t PUERTO_GENERICO_3_DIGITAL_5 = 45;
            static const uint8_t PUERTO_GENERICO_3_DIGITAL_6 = 46;
            static const uint8_t PUERTO_GENERICO_3_ANALOG_1 = PIN_A14;
            static const uint8_t PUERTO_GENERICO_3_ANALOG_2 = PIN_A15;

            MentorBitPuertos();
            void conectar(uint8_t port, MentorPort& module);

    };

#endif
