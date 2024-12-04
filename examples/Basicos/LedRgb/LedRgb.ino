/**
 * LedDRgb.ino - Ejemplo de uso de LED RGB del MentorBit
 * 
 * Creado el 25/08/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Encendido secuencial y combinado de los colores del RGB del MentorBit
 * utilizando la librería.
 */

#include <MentorBit.h>

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Inicializar pines apagados
    digitalWrite(miMentorBit.RGB_ROJO, HIGH);
    digitalWrite(miMentorBit.RGB_VERDE, HIGH);
    digitalWrite(miMentorBit.RGB_AZUL, HIGH);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el color rojo
    digitalWrite(miMentorBit.RGB_ROJO, LOW);
    digitalWrite(miMentorBit.RGB_VERDE, HIGH);
    digitalWrite(miMentorBit.RGB_AZUL, HIGH);
    delay(500);

    // Encendemos el color rojo y el verde
    digitalWrite(miMentorBit.RGB_ROJO, LOW);
    digitalWrite(miMentorBit.RGB_VERDE, LOW);
    digitalWrite(miMentorBit.RGB_AZUL, HIGH);
    delay(500);

    // Encendemos el color verde
    digitalWrite(miMentorBit.RGB_ROJO, HIGH);
    digitalWrite(miMentorBit.RGB_VERDE, LOW);
    digitalWrite(miMentorBit.RGB_AZUL, HIGH);
    delay(500);

    // Encendemos el color verde y el azul
    digitalWrite(miMentorBit.RGB_ROJO, HIGH);
    digitalWrite(miMentorBit.RGB_VERDE, LOW);
    digitalWrite(miMentorBit.RGB_AZUL, LOW);
    delay(500);

    // Encendemos el color Azul
    digitalWrite(miMentorBit.RGB_ROJO, HIGH);
    digitalWrite(miMentorBit.RGB_VERDE, HIGH);
    digitalWrite(miMentorBit.RGB_AZUL, LOW);
    delay(500);

    // Encendemos el color azul y el rojo
    digitalWrite(miMentorBit.RGB_ROJO, LOW);
    digitalWrite(miMentorBit.RGB_VERDE, HIGH);
    digitalWrite(miMentorBit.RGB_AZUL, LOW);
    delay(500);

}
