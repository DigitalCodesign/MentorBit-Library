/*
 * MentorBit.h - Librería base para MentorBit Arduino
 *
 * Creado el 24/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase base MentorBit,
 * referida al MentorBit compatible con Arduino y sus elementos básicos.
 * 
 * -> LEDs
 * -> LED RGB
 * -> Pulsadores
 * -> Zumbador
 * -> Potenciómetro
 */

#ifndef MentorBit_h
#define MentorBit_h

    #include "Arduino.h"

    class MentorBit
    {

        public:

            static const uint8_t LED_ROJO = 5;
            static const uint8_t LED_VERDE = 6;
            static const uint8_t LED_AZUL = 7;
            static const uint8_t RGB_ROJO = 8;
            static const uint8_t RGB_VERDE = 9;
            static const uint8_t RGB_AZUL = 10;
            static const uint8_t PULSADOR_PULLUP_DIGITAL = 22;
            static const uint8_t PULSADOR_PULLDOWN_DIGITAL = 23;
            static const uint8_t ZUMBADOR = 25;
            static const uint8_t POTENCIOMETRO = PIN_A0;
            static const uint8_t PULSADOR_PULLDOWN_ANALOGICO = PIN_A2;
            static const uint8_t PULSADOR_PULLUP_ANALOGICO = PIN_A3;

            MentorBit();

            void encenderLED(uint8_t led);
            void apagarLED(uint8_t led);
            void encenderRGB(uint8_t rojo, uint8_t verde, uint8_t azul);
            void apagarRGB();
            void generarTono(uint16_t frecuencia, uint8_t duracion);
            bool obtenerLecturaPulsador(uint8_t pulsador);
            uint16_t obtenerLecturaPotenciometro();

    };

#endif
