/**
 * SensoresDS18B20.ino - Ejemplo de uso de DS18B20 del Entrenador
 * 
 * Creado el 12/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Volcado de información del sensor al monitor serial.
 */

#include "Entrenador.h"
#include "EntrenadorSensores.h"

// Declaración de instancia de las clases
Entrenador miEntrenador;
EntrenadorSensores miEntrenadorSensores;

// Inicialización del sketch
void setup() {

    Serial.begin(9600);

}

// Bucle principal del sketch
void loop() {

    // Obtención de la lectura del sensor
    float temperatura = miEntrenadorSensores.obtenerTemperaturaDS18B20();

    // Mostrar datos por monitor serial
    Serial.println("--------------------");
    Serial.print("Lectura de temperatura: ");
    Serial.println(temperatura);

    delay(500);

}
