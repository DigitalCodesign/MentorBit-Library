/**
 * SensoresLDR.ino - Ejemplo de uso de MQ del Entrenador
 * 
 * Creado el 12/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido de un LED utilizando la medida del MQ del Entrenador
 * utilizando la librería.
 */

#include "Entrenador.h"
#include "EntrenadorSensores.h"

// Declaración de instancia de las clases
Entrenador miEntrenador;
EntrenadorSensores miEntrenadorSensores;

// Inicialización del sketch
void setup() {

    digitalWrite(miEntrenador.ledRojo, LOW);

}

// Bucle principal del sketch
void loop() {

    // Obtención de la lectura del sensor
    int lecturaMQ = analogRead(miEntrenadorSensores.MQpin);

    // Comprobación del valor de la lectura
    if(lecturaMQ > 500) {

        // Encender LED
        digitalWrite(miEntrenador.ledRojo, HIGH);

    } else {

        // Apagar LED
        digitalWrite(miEntrenador.ledRojo, LOW);

    }

    delay(250);

}
