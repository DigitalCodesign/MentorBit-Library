/**
 * LedDRgb.ino - Ejemplo de uso de LED RGB del MentorBit
 * 
 * Creado el 25/08/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Encendido secuencial y combinado de los colores del RGB del MentorBit
 * utilizando la librería.
 */

#include "MentorBit.h"

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Definición de pines como salida
    pinMode(miMentorBit.rgbRojo, OUTPUT);
    pinMode(miMentorBit.rgbVerde, OUTPUT);
    pinMode(miMentorBit.rgbAzul, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(miMentorBit.rgbRojo, LOW);
    digitalWrite(miMentorBit.rgbVerde, LOW);
    digitalWrite(miMentorBit.rgbAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el color rojo
    digitalWrite(miMentorBit.rgbRojo, HIGH);
    digitalWrite(miMentorBit.rgbVerde, LOW);
    digitalWrite(miMentorBit.rgbAzul, LOW);
    delay(500);

    // Encendemos el color rojo y el verde
    digitalWrite(miMentorBit.rgbRojo, HIGH);
    digitalWrite(miMentorBit.rgbVerde, HIGH);
    digitalWrite(miMentorBit.rgbAzul, LOW);
    delay(500);

    // Encendemos el color verde
    digitalWrite(miMentorBit.rgbRojo, LOW);
    digitalWrite(miMentorBit.rgbVerde, HIGH);
    digitalWrite(miMentorBit.rgbAzul, LOW);
    delay(500);

    // Encendemos el color verde y el azul
    digitalWrite(miMentorBit.rgbRojo, LOW);
    digitalWrite(miMentorBit.rgbVerde, HIGH);
    digitalWrite(miMentorBit.rgbAzul, HIGH);
    delay(500);

    // Encendemos el color Azul
    digitalWrite(miMentorBit.rgbRojo, LOW);
    digitalWrite(miMentorBit.rgbVerde, LOW);
    digitalWrite(miMentorBit.rgbAzul, HIGH);
    delay(500);

    // Encendemos el color azul y el rojo
    digitalWrite(miMentorBit.rgbRojo, HIGH);
    digitalWrite(miMentorBit.rgbVerde, LOW);
    digitalWrite(miMentorBit.rgbAzul, HIGH);
    delay(500);

}
