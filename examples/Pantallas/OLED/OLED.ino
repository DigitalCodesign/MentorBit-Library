/**
 * OLED.ino - Ejemplo de uso de la pantalla OLED del MentorBit
 * 
 * Creado el 13/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Mostrar por la pantalla el icono por defecto.
 */

#include "MentorBitPantallas.h"

// Declaración de instancia de las clases
MentorBitPantallas miMentorBitPantallas;

// Inicialización del sketch
void setup() {

    // Inicializamos la pantalla y mostramos el icono
    miMentorBitPantallas.inicializarOLED();
    miMentorBitPantallas.oled.display();

}

// Bucle principal del sketch
void loop() {

}
