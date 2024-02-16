/**
 * LedDeColores.ino - Ejemplo de uso de LEDs del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido secuencial de los LEDs de colores del Entrenador
 * utilizando la librería.
 */

#include "Entrenador.h"

// Declaración de instancia de la clase
Entrenador miEntrenador;

// Inicialización del sketch
void setup() {

    // Definición de pines como salida
    pinMode(miEntrenador.ledRojo, OUTPUT);
    pinMode(miEntrenador.ledVerde, OUTPUT);
    pinMode(miEntrenador.ledAzul, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(miEntrenador.ledRojo, LOW);
    digitalWrite(miEntrenador.ledVerde, LOW);
    digitalWrite(miEntrenador.ledAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el LED rojo solamente y esperamos
    digitalWrite(miEntrenador.ledRojo, HIGH);
    digitalWrite(miEntrenador.ledVerde, LOW);
    digitalWrite(miEntrenador.ledAzul, LOW);
    delay(500);

    // Encendemos el LED verde solamente y esperamos
    digitalWrite(miEntrenador.ledRojo, LOW);
    digitalWrite(miEntrenador.ledVerde, HIGH);
    digitalWrite(miEntrenador.ledAzul, LOW);
    delay(500);

    // Encendemos el LED azul solamente y esperamos
    digitalWrite(miEntrenador.ledRojo, LOW);
    digitalWrite(miEntrenador.ledVerde, LOW);
    digitalWrite(miEntrenador.ledAzul, HIGH);
    delay(500);

}
