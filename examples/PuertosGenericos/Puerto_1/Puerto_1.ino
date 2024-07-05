/**
 * Puerto_1.ino - Ejemplo de uso del puerto genérico 1 del MentorBit
 * 
 * Creado el 27/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido secuencial de los pines del puerto utilizando la librería.
 */

#include "MentorBitPuertos.h"

// Declaración de instancia de la clase
MentorBitPuertos miMentorBitPuertos;

// Inicialización del sketch
void setup() {

    // Establecer modo de uso de los pines
    pinMode(miMentorBitPuertos.puerto1_digital1, OUTPUT);
    pinMode(miMentorBitPuertos.puerto1_digital2, OUTPUT);
    pinMode(miMentorBitPuertos.puerto1_digital3, OUTPUT);
    pinMode(miMentorBitPuertos.puerto1_digital4, OUTPUT);
    pinMode(miMentorBitPuertos.puerto1_digital5, OUTPUT);
    pinMode(miMentorBitPuertos.puerto1_digital6, OUTPUT);
    pinMode(miMentorBitPuertos.puerto1_analog1, INPUT);
    pinMode(miMentorBitPuertos.puerto1_analog2, INPUT);

    // Inicializar pines apagados
    digitalWrite(miMentorBitPuertos.puerto1_digital1, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital2, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital3, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital4, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital5, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital6, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_analog1, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_analog2, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos secuencialmente los pines digitales
    digitalWrite(miMentorBitPuertos.puerto1_digital1, HIGH);
    digitalWrite(miMentorBitPuertos.puerto1_digital2, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital3, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital4, LOW);
    delay(500);
    digitalWrite(miMentorBitPuertos.puerto1_digital1, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital2, HIGH);
    digitalWrite(miMentorBitPuertos.puerto1_digital3, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital4, LOW);
    delay(500);
    digitalWrite(miMentorBitPuertos.puerto1_digital1, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital2, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital3, HIGH);
    digitalWrite(miMentorBitPuertos.puerto1_digital4, LOW);
    delay(500);
    digitalWrite(miMentorBitPuertos.puerto1_digital1, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital2, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital3, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital4, HIGH);
    delay(500);
    digitalWrite(miMentorBitPuertos.puerto1_digital1, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital2, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital3, LOW);
    digitalWrite(miMentorBitPuertos.puerto1_digital4, LOW);
    delay(500);

    // Encendemos secuencialmente los pines con PWM con distintos valores
    for(int i = 0 ; i < 256 ; i += 10) {
        analogWrite(miMentorBitPuertos.puerto1_digital5, i);
        delay(100);
    }
    analogWrite(miMentorBitPuertos.puerto1_digital5, 0);
    for(int i = 0 ; i < 256 ; i += 10) {
        analogWrite(miMentorBitPuertos.puerto1_digital6, i);
        delay(100);
    }
    analogWrite(miMentorBitPuertos.puerto1_digital6, 0);

}
