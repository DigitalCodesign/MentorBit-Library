/**
 * LDR.ino - Ejemplo de uso de LDR del Entrenador
 * 
 * Creado el 12/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido proporcional de un LED utilizando la medida de la fotorresistencia
 * del Entrenador utilizando la librería.
 */

#include "Entrenador.h"
#include "EntrenadorSensores.h"

// Declaración de instancia de las clases
Entrenador miEntrenador;
EntrenadorSensores miEntrenadorSensores;

// Inicialización del sketch
void setup() {

    digitalWrite(miEntrenador.ledAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Obtención y conversión de la lectura del sensor
    int lectura0a1023 = analogRead(miEntrenadorSensores.LDRpin);
    float lectura0a255 = (lectura0a1023 / 1023.00) * 255;

    // Modificación de la intensidad del LED
    analogWrite(miEntrenador.ledAzul, lectura0a255);
    delay(100);

}
