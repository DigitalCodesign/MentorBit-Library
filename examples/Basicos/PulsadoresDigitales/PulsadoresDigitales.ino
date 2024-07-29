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
    pinMode(miMentorBit.pulsadorPullUpDigital, INPUT);
    pinMode(miMentorBit.pulsadorPullDownDigital, INPUT);
    pinMode(miMentorBit.ledRojo, OUTPUT);
    pinMode(miMentorBit.rgbRojo, OUTPUT);

    // Inicializar pin del LED apagado
    digitalWrite(miMentorBit.ledRojo, LOW);
    digitalWrite(miMentorBit.rgbRojo, LOW);

}

// Bucle principal del sketch
void loop() {

    // Comprobar la lectura del pulsador Pull Up en pin digital
    if(digitalRead(miMentorBit.pulsadorPullUpDigital) == LOW)
    {

        // Encendemos el LED rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miMentorBit.ledRojo, HIGH);
        delay(250);
        digitalWrite(miMentorBit.ledRojo, LOW);

    }

    // Comprobar la lectura del pulsador Pull Down en pin digital
    if(digitalRead(miMentorBit.pulsadorPullDownDigital) == HIGH)
    {

        // Encendemos el LED del RGB rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miMentorBit.rgbRojo, HIGH);
        delay(250);
        digitalWrite(miMentorBit.rgbRojo, LOW);

    }

}

