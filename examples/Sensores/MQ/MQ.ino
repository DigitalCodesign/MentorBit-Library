/**
 * MQ.ino - Ejemplo de uso de MQ del MentorBit
 * 
 * Creado el 12/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido de un LED utilizando la medida del MQ del MentorBit
 * utilizando la librería.
 */

#include "MentorBit.h"
#include "MentorBitSensores.h"

// Declaración de instancia de las clases
MentorBit miMentorBit;
MentorBitSensores miMentorBitSensores;

// Inicialización del sketch
void setup() {

    digitalWrite(miMentorBit.ledRojo, LOW);

}

// Bucle principal del sketch
void loop() {

    // Obtención de la lectura del sensor
    int lecturaMQ = analogRead(miMentorBitSensores.MQpin);

    // Comprobación del valor de la lectura
    if(lecturaMQ > 500) {

        // Encender LED
        digitalWrite(miMentorBit.ledRojo, HIGH);

    } else {

        // Apagar LED
        digitalWrite(miMentorBit.ledRojo, LOW);

    }

    delay(250);

}
