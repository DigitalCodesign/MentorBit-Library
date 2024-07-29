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

    // Definición de zumbador como salida
    pinMode(miMentorBit.zumbador, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(miMentorBit.zumbador, LOW);

}

// Bucle principal del sketch
void loop() {

    // Bucle para generar diferentes frecuencias
    for(uint8_t i = 100 ; i < 1000 ; i =+ 100)
    {

        // Generar tono con la frecuencia dada por el bucle for
        tone(miMentorBit.zumbador, i, 100);

    }

    delay(500);

}
