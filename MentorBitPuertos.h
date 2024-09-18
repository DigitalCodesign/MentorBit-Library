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

#ifndef MentorBitPuertos_h
#define MentorBitPuertos_h

    #include "Arduino.h"

    #define PUERTO_1_DIGITAL_1 35
    #define PUERTO_1_DIGITAL_2 36
    #define PUERTO_1_DIGITAL_3 37
    #define PUERTO_1_DIGITAL_4 38
    #define PUERTO_1_DIGITAL_5 3
    #define PUERTO_1_DIGITAL_6 2
    #define PUERTO_1_ANALOG_1 PIN_A10
    #define PUERTO_1_ANALOG_2 PIN_A11

    #define PUERTO_2_DIGITAL_1 39
    #define PUERTO_2_DIGITAL_2 40
    #define PUERTO_2_DIGITAL_3 41
    #define PUERTO_2_DIGITAL_4 42
    #define PUERTO_2_DIGITAL_5 13
    #define PUERTO_2_DIGITAL_6 44
    #define PUERTO_2_ANALOG_1 PIN_A12
    #define PUERTO_2_ANALOG_2 PIN_A13

    #define PUERTO_3_DIGITAL_1 43
    #define PUERTO_3_DIGITAL_2 47
    #define PUERTO_3_DIGITAL_3 48
    #define PUERTO_3_DIGITAL_4 49
    #define PUERTO_3_DIGITAL_5 45
    #define PUERTO_3_DIGITAL_6 46
    #define PUERTO_3_ANALOG_1 PIN_A14
    #define PUERTO_3_ANALOG_2 PIN_A15

    class MentorBitPuertos
    {

        public:

            MentorBitPuertos();

    };

#endif
