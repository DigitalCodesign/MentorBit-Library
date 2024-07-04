/*
 * MentorBitDisplay.h - Librería del módulo de Display para MentorBit Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase MentorBitDisplay,
 * referida al MentorBit compatible con Arduino y el módulo de display 7 segmentos.
 * 
 */

#ifndef MentorBitDisplay_h
#define MentorBitDisplay_h

    #include "Arduino.h"
    #include "Wire.h"
    #include "Adafruit_GFX.h"
    #include "Adafruit_LEDBackpack.h"

    class MentorBitDisplay
    {

        public:

            MentorBitDisplay();

            void inicializarDisplay();
            void imprimir(char valor);
            void imprimir(String valor);
            void imprimir(int valor);
            void imprimir(double valor);

        private:

            uint8_t _dots[4];
            uint8_t _displayDirection;
            Adafruit_7segment myDisplay;

    };

#endif
