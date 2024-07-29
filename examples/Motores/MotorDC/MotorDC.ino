/**
 * MotorDC.ino - Ejemplo de uso del motor de corriente continua del MentorBit
 * 
 * Creado el 13/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Control del motor de corriente continua realizando giros en ambos sentidos
 * y a velocidades graduales
 */

#include "MentorBitMotores.h"

// Declaración de instancia de las clases
MentorBitMotores miMentorBitMotores;

// Inicialización del sketch
void setup() {

}

// Bucle principal del sketch
void loop() {

    // Giro gradual del motor en un sentido
    for(int i = 0; i < 256 ; i = i + 50) {

        miMentorBitMotores.moverMotorDC(i, 0);
        delay(250);

    }

    // Parada momentánea
    delay(500);
    miMentorBitMotores.moverMotorDC(0, 0);

    // Giro gradual del motor en el otro sentido
    for(int i = 0; i < 256 ; i = i + 50) {

        miMentorBitMotores.moverMotorDC(i, 1);
        delay(250);

    }

    // Parada momentánea
    delay(500);
    miMentorBitMotores.moverMotorDC(0, 0);

}
