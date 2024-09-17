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

    #define LED_ROJO 5
    #define LED_VERDE 6
    #define LED_AZUL 7
    #define RGB_ROJO 8
    #define RGB_VERDE 9
    #define RGB_AZUL 10
    #define PULSADOR_PULLUP_DIGITAL 22
    #define PULSADOR_PULLDOWN_DIGITAL 23
    #define ZUMBADOR 25
    #define POTENCIOMETRO PIN_A0
    #define PULSADOR_PULLDOWN_ANALOGICO PIN_A2
    #define PULSADOR_PULLUP_ANALOGICO PIN_A3

    class MentorBit
    {

        public:

            MentorBit();

            uint8_t led_rojo;
            uint8_t led_verde;
            uint8_t led_azul;
            uint8_t rgb_rojo;
            uint8_t rgb_verde;
            uint8_t rgb_azul;
            uint8_t pulsador_pullup_digital;
            uint8_t pulsado_pulldown_digital;
            uint8_t zumbador;
            uint8_t potenciometro;
            uint8_t pulsador_pulldown_analogico;
            uint8_t pulsador_pullup_analogico;

    };

#endif
