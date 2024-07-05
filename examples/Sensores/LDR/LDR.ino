/**
 * LDR.ino - Ejemplo de uso de LDR del MentorBit
 * 
 * Creado el 12/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido proporcional de un LED utilizando la medida de la fotorresistencia
 * del MentorBit utilizando la librería.
 */

#include "MentorBit.h"
#include "MentorBitSensores.h"

// Declaración de instancia de las clases
MentorBit miMentorBit;
MentorBitSensores miMentorBitSensores;

// Inicialización del sketch
void setup() {

    digitalWrite(miMentorBit.ledAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Obtención y conversión de la lectura del sensor
    int lectura0a1023 = analogRead(miMentorBitSensores.LDRpin);
    float lectura0a255 = (lectura0a1023 / 1023.00) * 255;

    // Modificación de la intensidad del LED
    analogWrite(miMentorBit.ledAzul, lectura0a255);
    delay(100);

}
