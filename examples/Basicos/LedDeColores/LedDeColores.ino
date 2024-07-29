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
    pinMode(miMentorBit.ledRojo, OUTPUT);
    pinMode(miMentorBit.ledVerde, OUTPUT);
    pinMode(miMentorBit.ledAzul, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(miMentorBit.ledRojo, LOW);
    digitalWrite(miMentorBit.ledVerde, LOW);
    digitalWrite(miMentorBit.ledAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el LED rojo solamente y esperamos
    digitalWrite(miMentorBit.ledRojo, HIGH);
    digitalWrite(miMentorBit.ledVerde, LOW);
    digitalWrite(miMentorBit.ledAzul, LOW);
    delay(500);

    // Encendemos el LED verde solamente y esperamos
    digitalWrite(miMentorBit.ledRojo, LOW);
    digitalWrite(miMentorBit.ledVerde, HIGH);
    digitalWrite(miMentorBit.ledAzul, LOW);
    delay(500);

    // Encendemos el LED azul solamente y esperamos
    digitalWrite(miMentorBit.ledRojo, LOW);
    digitalWrite(miMentorBit.ledVerde, LOW);
    digitalWrite(miMentorBit.ledAzul, HIGH);
    delay(500);

}
