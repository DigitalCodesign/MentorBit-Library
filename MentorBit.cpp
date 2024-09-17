/*
 * MentorBit.cpp - Librería base para MentorBit Arduino
 *
 * Creado el 24/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase base MentorBit,
 * referida al MentorBit compatible con Arduino.
 */

#include "MentorBit.h"

/*
 * Constructor de la clase base del MentorBit.
 *
 * Devuelve una instancia de la clase MentorBit que provee los pines de conexión
 * de los elementos básicos de la placa.
 * 
 * -> LED de colores
 * -> LED RGB
 * -> Pulsadores
 * -> Zumbador
 * -> Potenciómetro
 */
MentorBit::MentorBit()
{

    led_rojo = LED_ROJO;
    led_verde = LED_VERDE;
    led_azul = LED_AZUL;
    rgb_rojo = RGB_ROJO;
    rgb_verde = RGB_VERDE;
    rgb_azul = RGB_AZUL;
    pulsador_pullup_digital = PULSADOR_PULLUP_DIGITAL;
    pulsado_pulldown_digital = PULSADOR_PULLDOWN_DIGITAL;
    zumbador = ZUMBADOR;
    potenciometro = POTENCIOMETRO;
    pulsador_pulldown_analogico = PULSADOR_PULLDOWN_ANALOGICO;
    pulsador_pullup_analogico = PULSADOR_PULLUP_ANALOGICO;

    pinMode(led_rojo, OUTPUT);
    pinMode(led_verde, OUTPUT);
    pinMode(led_azul, OUTPUT);
    pinMode(rgb_rojo, OUTPUT);
    pinMode(rgb_verde, OUTPUT);
    pinMode(rgb_azul, OUTPUT);
    pinMode(pulsador_pullup_digital, INPUT);
    pinMode(pulsado_pulldown_digital, INPUT);
    pinMode(zumbador, OUTPUT);
    pinMode(potenciometro, INPUT);
    pinMode(pulsador_pulldown_analogico, INPUT);
    pinMode(pulsador_pullup_analogico, INPUT);

}
