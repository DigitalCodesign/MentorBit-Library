/**
 * Display7Segments.ino - Ejemplo de uso del Display 7 segmentos del MentorBit
 * 
 * Creado el 15/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Mostrar una variedad de valores por el display 7 segmentos del MentorBit
 * utilizando la librería.
 */

#include <MentorBitDisplay.h>

// Declaración de instancia de la clase
MentorBitDisplay miMentorBitDisplay;

// Inicialización del sketch
void setup() {

    // Inicializar Display 7 segmentos
    miMentorBitDisplay.inicializarDisplay();

    // Mostrar valores de diferentes tipos
    miMentorBitDisplay.imprimir('P');  // char
    delay(1000);
    miMentorBitDisplay.imprimir("Hi"); // String
    delay(1000);
    miMentorBitDisplay.imprimir(234);  // int
    delay(1000);
    miMentorBitDisplay.imprimir(7.21); // float

}

// Bucle principal del sketch
void loop() {}
