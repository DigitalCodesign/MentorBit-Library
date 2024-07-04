/**
 * Potenciometro.ino - Ejemplo de uso del potenciometro del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Ajuste de brillo de un LED con la lectura del potenciómetro.
 */

#include "Entrenador.h"

// Declaración de instancia de la clase
Entrenador miEntrenador;

// Inicialización del sketch
void setup() {

    // Definición de LED como salida
    pinMode(miEntrenador.ledRojo, OUTPUT);

    // Inicializar pines apagados
    analogWrite(miEntrenador.ledRojo, 0);

}

// Bucle principal del sketch
void loop() {

    int lectura0a1023 = analogRead(miEntrenador.potenciometro);
    float lectura0a255 = (lectura0a1023 / 1023.00) * 255;

    analogWrite(miEntrenador.ledRojo, lectura0a255);
    delay(100);

}
