/**
 * LCD.ino - Ejemplo de uso de la pantalla LCD del MentorBit
 * 
 * Creado el 13/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Mostrar por la pantalla el mensaje "Hello, world!".
 */

#include "MentorBitPantallas.h"

// Declaración de instancia de las clases
MentorBitPantallas miMentorBitPantallas;

// Inicialización del sketch
void setup() {

    // Inicializamos la pantalla y mostramos el mensaje.
    miMentorBitPantallas.inicializarLCD();
    miMentorBitPantallas.lcd.backlight();
    miMentorBitPantallas.lcd.setCursor(0, 0);
    miMentorBitPantallas.lcd.print("Hello, world!");

}

// Bucle principal del sketch
void loop() {

}
