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

    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AZUL, OUTPUT);
    pinMode(RGB_ROJO, OUTPUT);
    pinMode(RGB_VERDE, OUTPUT);
    pinMode(RGB_AZUL, OUTPUT);
    pinMode(ZUMBADOR, OUTPUT);

}

/**
 * Enciende el diodo LED indicado como parámetro del método.
 */
void MentorBit::encenderLED(uint8_t led) {

    digitalWrite(led, HIGH);

}

/**
 * Apaga el diodo LED indicado como parámetro del método.
 */
void MentorBit::apagarLED(uint8_t led) {

    digitalWrite(led, LOW);

}

/**
 * Pone el LED RGB en los tonos e intensidades definidas para el color
 * indicado como parámetro del método.
 */
void MentorBit::encenderRGB(uint8_t rojo, uint8_t verde, uint8_t azul) {

    analogWrite(RGB_ROJO, rojo);
    analogWrite(RGB_VERDE, verde);
    analogWrite(RGB_AZUL, azul);

}

/**
 * Apaga el LED RGB por completo.
 */
void MentorBit::apagarRGB() {

    digitalWrite(RGB_ROJO, LOW);
    digitalWrite(RGB_VERDE, LOW);
    digitalWrite(RGB_AZUL, LOW);

}

/**
 * Genera un tono de frecuencia y duración determiadas según los
 * parámetros dados al método.
 */
void MentorBit::generarTono(uint16_t frecuencia, uint8_t duracion) {

    tone(ZUMBADOR, frecuencia, duracion);

}

/**
 * Devuelve la lectura digital o analógica obtenida de los puertos
 * donde se encuentran conectados los pulsadores según el indicado
 * como parámetro del método.
 */
bool MentorBit::obtenerLecturaPulsador(uint8_t pulsador) {

    return digitalRead(pulsador);

}

/**
 * Devuelve la lectura analógica obtenida del puerto donde se
 * encuentra conectado el Potenciómetro.
 */
uint16_t MentorBit::obtenerLecturaPotenciometro() {

    return analogRead(POTENCIOMETRO);

}
