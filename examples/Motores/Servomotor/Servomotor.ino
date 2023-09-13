/**
 * Servomotor.ino - Ejemplo de uso del servomotor del Entrenador
 * 
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Control del servomotor realizando movimiento de diferentes ángulos.
 */

#include "EntrenadorMotores.h"

// Declaración de instancia de las clases
EntrenadorMotores miEntrenadorMotores;

// Inicialización del sketch
void setup() {

    miEntrenadorMotores.inicializarServo();

}

// Bucle principal del sketch
void loop() {

    // Mover el servomotor a 0º
    miEntrenadorMotores.moverServo(180);
    delay(1000);

    // Mover el servomotor a 30º
    miEntrenadorMotores.moverServo(150);
    delay(1000);

    // Mover el servomotor a 60º
    miEntrenadorMotores.moverServo(120);
    delay(1000);

    // Mover el servomotor a 90º
    miEntrenadorMotores.moverServo(90);
    delay(1000);

}
