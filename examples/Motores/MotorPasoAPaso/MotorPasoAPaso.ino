/**
 * MotorPasoAPaso.ino - Ejemplo de uso del motor paso a paso del Entrenador
 * 
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Control del motor paso a paso realizando un giro completo en ambos sentidos.
 */

#include "EntrenadorMotores.h"

// Declaración de instancia de las clases
EntrenadorMotores miEntrenadorMotores;

// Inicialización del sketch
void setup() {

}

// Bucle principal del sketch
void loop() {

    // Mover el motor en un sentido
    miEntrenadorMotores.moverMotorPP(256, 0);
    delay(500);

    // Mover el motor en el otro sentido
    miEntrenadorMotores.moverMotorPP(256, 1);
    delay(500);

}
