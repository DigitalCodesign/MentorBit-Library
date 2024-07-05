/**
 * Potenciometro.ino - Ejemplo de uso del potenciometro del MentorBit
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Ajuste de brillo de un LED con la lectura del potenciómetro.
 */

#include "MentorBit.h"

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Definición de LED como salida
    pinMode(miMentorBit.ledRojo, OUTPUT);

    // Inicializar pines apagados
    analogWrite(miMentorBit.ledRojo, 0);

}

// Bucle principal del sketch
void loop() {

    int lectura0a1023 = analogRead(miMentorBit.potenciometro);
    float lectura0a255 = (lectura0a1023 / 1023.00) * 255;

    analogWrite(miMentorBit.ledRojo, lectura0a255);
    delay(100);

}
