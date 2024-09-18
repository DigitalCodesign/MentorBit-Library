/**
 * Potenciometro.ino - Ejemplo de uso del potenciometro del MentorBit
 * 
 * Creado el 25/08/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Ajuste de brillo de un LED con la lectura del potenciómetro.
 */

#include "MentorBit.h"

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Inicializar pines apagados
    analogWrite(miMentorBit.LED_ROJO, 0);

}

// Bucle principal del sketch
void loop() {

    int lectura0a1023 = analogRead(miMentorBit.POTENCIOMETRO);
    float lectura0a255 = (lectura0a1023 / 1023.00) * 255;

    analogWrite(miMentorBit.LED_ROJO, lectura0a255);
    delay(100);

}
