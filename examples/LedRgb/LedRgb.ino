/**
 * LedDRgb.ino - Ejemplo de uso de LED RGB del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido secuencial y combinado de los colores del RGB del Entrenador
 * utilizando la librería.
 */

#include "Entrenador.h"

// Declaración de instancia de la clase
Entrenador miEntrenador();

// Inicialización del sketch
void setup() {

    // Definición de pines como salida
    pinMode(miEntrenador.rgbRojo, OUTPUT);
    pinMode(miEntrenador.rgbVerde, OUTPUT);
    pinMode(miEntrenador.rgbAzul, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(miEntrenador.rgbRojo, LOW);
    digitalWrite(miEntrenador.rgbVerde, LOW);
    digitalWrite(miEntrenador.rgbAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el color rojo
    digitalWrite(miEntrenador.rgbRojo, HIGH);
    digitalWrite(miEntrenador.rgbVerde, LOW);
    digitalWrite(miEntrenador.rgbAzul, LOW);
    delay(500);

    // Encendemos el color rojo y el verde
    digitalWrite(miEntrenador.rgbRojo, HIGH);
    digitalWrite(miEntrenador.rgbVerde, HIGH);
    digitalWrite(miEntrenador.rgbAzul, LOW);
    delay(500);

    // Encendemos el color verde
    digitalWrite(miEntrenador.rgbRojo, LOW);
    digitalWrite(miEntrenador.rgbVerde, HIGH);
    digitalWrite(miEntrenador.rgbAzul, LOW);
    delay(500);

    // Encendemos el color verde y el azul
    digitalWrite(miEntrenador.rgbRojo, LOW);
    digitalWrite(miEntrenador.rgbVerde, HIGH);
    digitalWrite(miEntrenador.rgbAzul, HIGH);
    delay(500);

    // Encendemos el color Azul
    digitalWrite(miEntrenador.rgbRojo, LOW);
    digitalWrite(miEntrenador.rgbVerde, LOW);
    digitalWrite(miEntrenador.rgbAzul, HIGH);
    delay(500);

    // Encendemos el color azul y el rojo
    digitalWrite(miEntrenador.rgbRojo, HIGH);
    digitalWrite(miEntrenador.rgbVerde, LOW);
    digitalWrite(miEntrenador.rgbAzul, HIGH);
    delay(500);

}
