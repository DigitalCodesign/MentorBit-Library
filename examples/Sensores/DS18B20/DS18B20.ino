/**
 * DS18B20.ino - Ejemplo de uso de DS18B20 del MentorBit
 * 
 * Creado el 12/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Volcado de información del sensor al monitor serial.
 */

#include <MentorBitSensores.h>

// Declaración de instancia de las clases
MentorBitSensores miMentorBitSensores;

// Inicialización del sketch
void setup() {

    Serial.begin(9600);

}

// Bucle principal del sketch
void loop() {

    // Obtención de la lectura del sensor
    float temperatura = miMentorBitSensores.obtenerTemperaturaDS18B20();

    // Mostrar datos por monitor serial
    Serial.println("--------------------");
    Serial.print("Lectura de temperatura: ");
    Serial.println(temperatura);

    delay(500);

}
