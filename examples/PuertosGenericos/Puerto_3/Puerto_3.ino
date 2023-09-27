/**
 * Puerto_1.ino - Ejemplo de uso del puerto genérico 3 del Entrenador
 * 
 * Creado el 27/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido secuencial de los pines del puerto utilizando la librería.
 */

#include "EntrenadorPuertos.h"

// Declaración de instancia de la clase
EntrenadorPuertos miEntrenadorPuertos;

// Inicialización del sketch
void setup() {

    // Establecer modo de uso de los pines
    pinMode(miEntrenadorPuertos.puerto3_digital1, OUTPUT);
    pinMode(miEntrenadorPuertos.puerto3_digital2, OUTPUT);
    pinMode(miEntrenadorPuertos.puerto3_digital3, OUTPUT);
    pinMode(miEntrenadorPuertos.puerto3_digital4, OUTPUT);
    pinMode(miEntrenadorPuertos.puerto3_digital5, OUTPUT);
    pinMode(miEntrenadorPuertos.puerto3_digital6, OUTPUT);
    pinMode(miEntrenadorPuertos.puerto3_analog1, INPUT);
    pinMode(miEntrenadorPuertos.puerto3_analog2, INPUT);

    // Inicializar pines apagados
    digitalWrite(miEntrenadorPuertos.puerto3_digital1, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital2, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital3, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital4, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital5, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital6, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_analog1, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_analog2, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos secuencialmente los pines digitales
    digitalWrite(miEntrenadorPuertos.puerto3_digital1, HIGH);
    digitalWrite(miEntrenadorPuertos.puerto3_digital2, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital3, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital4, LOW);
    delay(500);
    digitalWrite(miEntrenadorPuertos.puerto3_digital1, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital2, HIGH);
    digitalWrite(miEntrenadorPuertos.puerto3_digital3, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital4, LOW);
    delay(500);
    digitalWrite(miEntrenadorPuertos.puerto3_digital1, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital2, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital3, HIGH);
    digitalWrite(miEntrenadorPuertos.puerto3_digital4, LOW);
    delay(500);
    digitalWrite(miEntrenadorPuertos.puerto3_digital1, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital2, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital3, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital4, HIGH);
    delay(500);
    digitalWrite(miEntrenadorPuertos.puerto3_digital1, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital2, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital3, LOW);
    digitalWrite(miEntrenadorPuertos.puerto3_digital4, LOW);
    delay(500);

    // Encendemos secuencialmente los pines con PWM con distintos valores
    for(int i = 0 ; i < 256 ; i += 10) {
        analogWrite(miEntrenadorPuertos.puerto3_digital5, i);
        delay(100);
    }
    analogWrite(miEntrenadorPuertos.puerto3_digital5, 0);
    for(int i = 0 ; i < 256 ; i += 10) {
        analogWrite(miEntrenadorPuertos.puerto3_digital6, i);
        delay(100);
    }
    analogWrite(miEntrenadorPuertos.puerto3_digital6, 0);

}
