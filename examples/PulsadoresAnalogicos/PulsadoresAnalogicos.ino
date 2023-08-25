/**
 * PulsadoresAnalogicos.ino - Ejemplo de uso de Pulsadores del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido de LED en función del botón pulsado.
 */

#include "Entrenador.h"

// Declaración de instancia de la clase
Entrenador miEntrenador();

// Inicialización del sketch
void setup() {

    // Definición de pines como salida para los LED
    pinMode(miEntrenador.ledRojo, OUTPUT);
    pinMode(miEntrenador.rgbRojo, OUTPUT);

    // Inicializar pin de los LED apagado
    digitalWrite(miEntrenador.ledRojo, LOW);
    digitalWrite(miEntrenador.rgbRojo, LOW);

}

// Bucle principal del sketch
void loop() {

    // Comprobar la lectura del pulsador Pull Up en pin analogico
    if(analogRead(miEntrenador.pulsadorPullUpAnalogico) < 500)
    {

        // Encendemos el LED rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miEntrenador.ledRojo, HIGH);
        delay(250);
        digitalWrite(miEntrenador.ledRojo, LOW);

    }

    // Comprobar la lectura del pulsador Pull Down en pin analogico
    if(analogRead(miEntrenador.pulsadorPullDownAnalogico) > 500)
    {

        // Encendemos el LED RGB rojo durante un cuarto de segundo (0'25s)
        digitalWrite(miEntrenador.rgbRojo, HIGH);
        delay(250);
        digitalWrite(miEntrenador.rgbRojo, LOW);

    }

}

