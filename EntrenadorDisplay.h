/*
 * EntrenadorDisplay.h - Librería del módulo de Display para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorDisplay,
 * referida al Entrenador compatible con Arduino y el módulo de display 7 segmentos.
 * 
 */

#ifndef EntrenadorDisplay_h
#define EntrenadorDisplay_h

    #include "Arduino.h"

    class EntrenadorDisplay
    {

        public:

            EntrenadorDisplay();

        private:

            uint8_t displayDirection;

    }
