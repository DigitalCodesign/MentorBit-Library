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
    #include "Wire.h"
    #include "Adafruit_GFX.h"
    #include "Adafruit_LEDBackpack.h"

    class EntrenadorDisplay
    {

        public:

            EntrenadorDisplay();

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
