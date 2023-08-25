/**
 * Zumbador.ino - Ejemplo de uso del zumbador del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Generación de tonos secuencial con el zumbador.
 */

#include "Entrenador.h"

// Declaración de instancia de la clase
Entrenador miEntrenador;

// Inicialización del sketch
void setup() {

    // Definición de zumbador como salida
    pinMode(miEntrenador.zumbador, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(miEntrenador.zumbador, LOW);

}

// Bucle principal del sketch
void loop() {

    // Bucle para generar diferentes frecuencias
    for(uint8_t i = 100 ; i < 1000 ; i =+ 100)
    {

        // Generar tono con la frecuencia dada por el bucle for
        tone(miEntrenador.zumbador, i, 100);

    }

    delay(500);

}
