/**
 * Display7Segments.ino - Ejemplo de uso del Display 7 segmentos del Entrenador
 * 
 * Creado el 15/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Mostrar una variedad de valores por el display 7 segmentos del Entrenador
 * utilizando la librería.
 */

#include <EntrenadorDisplay.h>

// Declaración de instancia de la clase
EntrenadorDisplay miEntrenadorDisplay;

// Inicialización del sketch
void setup() {

    // Inicializar Display 7 segmentos
    miEntrenadorDisplay.inicializarDisplay();

    // Mostrar valores de diferentes tipos
    miEntrenadorDisplay.imprimir('P');  // char
    delay(1000);
    miEntrenadorDisplay.imprimir("Hi"); // String
    delay(1000);
    miEntrenadorDisplay.imprimir(234);  // int
    delay(1000);
    miEntrenadorDisplay.imprimir(7.21); // float

}

// Bucle principal del sketch
void loop() {}
