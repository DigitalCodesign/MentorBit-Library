/**
 * SensoresDHT.ino - Ejemplo de uso de DHT del Entrenador
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

    // Obtención de las lecturas del sensor
    float temperatura = miEntrenadorSensores.obtenerTemperaturaDHT();
    float humedad = miEntrenadorSensores.obtenerHumedadDHT();

    // Mostrar datos por monitor serial
    Serial.println("--------------------");
    Serial.print("Lectura de temperatura: ");
    Serial.println(temperatura);
    Serial.print("Lectura de humedad: ");
    Serial.println(humedad);

    delay(500);

}
