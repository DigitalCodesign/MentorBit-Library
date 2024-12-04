/**
 * Servomotor.ino - Ejemplo de uso del servomotor del MentorBit
 * 
 * Creado el 13/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Control del servomotor realizando movimiento de diferentes ángulos.
 */

#include <MentorBitMotores.h>

// Declaración de instancia de las clases
MentorBitMotores miMentorBitMotores;

// Inicialización del sketch
void setup() {

    miMentorBitMotores.inicializarServo(miMentorBitMotores.SERVOMOTOR_1);

}

// Bucle principal del sketch
void loop() {

    // Mover el servomotor a 180º
    miMentorBitMotores.moverServo(miMentorBitMotores.SERVOMOTOR_1, 180);
    delay(1000);

    // Mover el servomotor a 150º
    miMentorBitMotores.moverServo(miMentorBitMotores.SERVOMOTOR_1, 150);
    delay(1000);

    // Mover el servomotor a 120º
    miMentorBitMotores.moverServo(miMentorBitMotores.SERVOMOTOR_1, 120);
    delay(1000);

    // Mover el servomotor a 90º
    miMentorBitMotores.moverServo(miMentorBitMotores.SERVOMOTOR_1, 90);
    delay(1000);

}
