/**
 * PulsadoresAnalogicos.ino - Ejemplo de uso de Pulsadores del MentorBit
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido de LED en función del botón pulsado.
 */

#include "MentorBit.h"

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Definición de pines como salida para los LED
    pinMode(miMentorBit.ledRojo, OUTPUT);
    pinMode(miMentorBit.rgbRojo, OUTPUT);

    // Inicializar pin de los LED apagado
    digitalWrite(miMentorBit.ledRojo, LOW);
    digitalWrite(miMentorBit.rgbRojo, LOW);

}

// Bucle principal del sketch
void loop() {

    // Comprobar la lectura del pulsador Pull Up en pin analogico
    if(analogRead(miMentorBit.pulsadorPullUpAnalogico) < 500)
    {

        // Encendemos el LED rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miMentorBit.ledRojo, HIGH);
        delay(250);
        digitalWrite(miMentorBit.ledRojo, LOW);

    }

    // Comprobar la lectura del pulsador Pull Down en pin analogico
    if(analogRead(miMentorBit.pulsadorPullDownAnalogico) > 500)
    {

        // Encendemos el LED RGB rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miMentorBit.rgbRojo, HIGH);
        delay(250);
        digitalWrite(miMentorBit.rgbRojo, LOW);

    }

}

