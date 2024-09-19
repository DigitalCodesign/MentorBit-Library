/**
 * Zumbador.ino - Ejemplo de uso del zumbador del MentorBit
 * 
 * Creado el 25/08/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Generación de tonos secuencial con el zumbador.
 */

#include "MentorBit.h"

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Inicializar pines apagados
    digitalWrite(miMentorBit.ZUMBADOR, LOW);

}

// Bucle principal del sketch
void loop() {

    // Bucle para generar diferentes frecuencias
    for(uint8_t i = 200 ; i <= 5000 ; i += 100) {

        // Generar tono con la frecuencia dada por el bucle for
        tone(miMentorBit.ZUMBADOR, i);
        delay(100);

    }

    noTone(miMentorBit.ZUMBADOR);
    delay(1000);

}
