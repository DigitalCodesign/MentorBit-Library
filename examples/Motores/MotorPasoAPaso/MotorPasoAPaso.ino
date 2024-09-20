/**
 * MotorPasoAPaso.ino - Ejemplo de uso del motor paso a paso del MentorBit
 * 
 * Creado el 13/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Control del motor paso a paso realizando un giro completo en ambos sentidos.
 */

#include <MentorBitMotores.h>

// Declaración de instancia de las clases
MentorBitMotores miMentorBitMotores;

// Inicialización del sketch
void setup() {

}

// Bucle principal del sketch
void loop() {

    // Mover el motor en un sentido
    miMentorBitMotores.moverMotorPP(256, 0);
    delay(500);

    // Mover el motor en el otro sentido
    miMentorBitMotores.moverMotorPP(256, 1);
    delay(500);

}
