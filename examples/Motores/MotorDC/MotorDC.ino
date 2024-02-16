/**
 * MotorDC.ino - Ejemplo de uso del motor de corriente continua del Entrenador
 * 
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Control del motor de corriente continua realizando giros en ambos sentidos
 * y a velocidades graduales
 */

#include "EntrenadorMotores.h"

// Declaración de instancia de las clases
EntrenadorMotores miEntrenadorMotores;

// Inicialización del sketch
void setup() {

}

// Bucle principal del sketch
void loop() {

    // Giro gradual del motor en un sentido
    for(int i = 0; i < 256 ; i = i + 50) {

        miEntrenadorMotores.moverMotorDC(i, 0);
        delay(250);

    }

    // Parada momentánea
    delay(500);
    miEntrenadorMotores.moverMotorDC(0, 0);

    // Giro gradual del motor en el otro sentido
    for(int i = 0; i < 256 ; i = i + 50) {

        miEntrenadorMotores.moverMotorDC(i, 1);
        delay(250);

    }

    // Parada momentánea
    delay(500);
    miEntrenadorMotores.moverMotorDC(0, 0);

}
