/**
 * LedDeColores.ino - Ejemplo de uso de LEDs del MentorBit
 * 
 * Creado el 25/08/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Encendido secuencial de los LEDs de colores del MentorBit
 * utilizando la librería.
 */

#include "MentorBit.h"

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Definición de pines como salida
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AZUL, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el LED rojo solamente y esperamos
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    delay(500);

    // Encendemos el LED verde solamente y esperamos
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, LOW);
    delay(500);

    // Encendemos el LED azul solamente y esperamos
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, HIGH);
    delay(500);

}
