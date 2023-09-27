/**
 * LCD.ino - Ejemplo de uso de la pantalla LCD del Entrenador
 * 
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Mostrar por la pantalla el mensaje "Hello, world!".
 */

#include "EntrenadorPantallas.h"

// Declaración de instancia de las clases
EntrenadorPantallas miEntrenadorPantallas;

// Inicialización del sketch
void setup() {

    // Inicializamos la pantalla y mostramos el mensaje.
    miEntrenadorPantallas.inicializarLCD();
    miEntrenadorPantallas.lcd.backlight();
    miEntrenadorPantallas.lcd.setCursor(0, 0);
    miEntrenadorPantallas.lcd.print("Hello, world!");

}

// Bucle principal del sketch
void loop() {

}
