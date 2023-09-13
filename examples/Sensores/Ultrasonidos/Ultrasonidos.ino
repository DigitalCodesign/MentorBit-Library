/**
 * SensoresUltrasonidos.ino - Ejemplo de uso de Ultrasonidos del Entrenador
 * 
 * Creado el 12/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Volcado de información del sensor al monitor serial.
 */

#include "EntrenadorSensores.h"

// Declaración de instancia de las clases
EntrenadorSensores miEntrenadorSensores;

// Inicialización del sketch
void setup() {

    Serial.begin(9600);

}

// Bucle principal del sketch
void loop() {

    // Obtención de la lectura del sensor
    float distancia = miEntrenadorSensores.obtenerDistanciaUlrasonidos();

    // Mostrar datos por monitor serial
    Serial.println("--------------------");
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    delay(500);

}
