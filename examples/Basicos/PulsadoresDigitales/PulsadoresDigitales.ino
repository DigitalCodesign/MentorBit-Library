/**
 * PulsadoresDigitales.ino - Ejemplo de uso de pulsadores del MentorBit
 * 
 * Creado el 25/08/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Encendido de LED en función del botón pulsado.
 */

#include "MentorBit.h"

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Definición de pines como entradas para los pulsadores y salida para los LED
    pinMode(miMentorBit.PULSADOR_PULLUP_DIGITAL, INPUT);
    pinMode(miMentorBit.PULSADOR_PULLDOWN_DIGITAL, INPUT);
    pinMode(miMentorBit.LED_ROJO, OUTPUT);
    pinMode(miMentorBit.RGB_ROJO, OUTPUT);

    // Inicializar pin del LED apagado
    digitalWrite(miMentorBit.LED_ROJO, LOW);
    digitalWrite(miMentorBit.RGB_ROJO, LOW);

}

// Bucle principal del sketch
void loop() {

    // Comprobar la lectura del pulsador Pull Up en pin digital
    if(digitalRead(miMentorBit.PULSADOR_PULLUP_DIGITAL) == LOW)
    {

        // Encendemos el LED rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miMentorBit.LED_ROJO, HIGH);
        delay(250);
        digitalWrite(miMentorBit.LED_ROJO, LOW);

    }

    // Comprobar la lectura del pulsador Pull Down en pin digital
    if(digitalRead(miMentorBit.PULSADOR_PULLDOWN_DIGITAL) == HIGH)
    {

        // Encendemos el LED del RGB rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miMentorBit.RGB_ROJO, HIGH);
        delay(250);
        digitalWrite(miMentorBit.RGB_ROJO, LOW);

    }

}

