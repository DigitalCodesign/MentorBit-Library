/*
 * EntrenadorPuertos.h - Librería de los puertos genéricos para Entrenador Arduino
 *
 * Creado el 27/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase base EntrenadorPuertos,
 * referida al Entrenador compatible con Arduino y sus puertos genéricos.
 * 
 * -> Puerto genérico 1
 * -> Puerto genérico 2
 * -> Puerto genérico 3
 */

#ifndef EntrenadorPuertos_h
#define EntrenadorPuertos_h

    #include "Arduino.h"

    class EntrenadorPuertos
    {

        public:

            EntrenadorPuertos();

            uint8_t puerto1_digital1;
            uint8_t puerto1_digital2;
            uint8_t puerto1_digital3;
            uint8_t puerto1_digital4;
            uint8_t puerto1_digital5;
            uint8_t puerto1_digital6;
            uint8_t puerto1_analog1;
            uint8_t puerto1_analog2;

            uint8_t puerto2_digital1;
            uint8_t puerto2_digital2;
            uint8_t puerto2_digital3;
            uint8_t puerto2_digital4;
            uint8_t puerto2_digital5;
            uint8_t puerto2_digital6;
            uint8_t puerto2_analog1;
            uint8_t puerto2_analog2;

            uint8_t puerto3_digital1;
            uint8_t puerto3_digital2;
            uint8_t puerto3_digital3;
            uint8_t puerto3_digital4;
            uint8_t puerto3_digital5;
            uint8_t puerto3_digital6;
            uint8_t puerto3_analog1;
            uint8_t puerto3_analog2;

    };

#endif
