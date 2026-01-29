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

    #include "Wire.h"

    class MentorBitDisplay
    {

        public:

            MentorBitDisplay();

            void inicializarDisplay();
            void imprimir(String valor);
            void imprimir(int valor);
            void imprimir(double valor);

        private:

            uint8_t _display_buffer[8];
            uint8_t _display_address;
            void _writeDisplay();
            uint8_t _charToSegmento(char c);

    };

#endif
