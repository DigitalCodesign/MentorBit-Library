/**
 * OLED.ino - Ejemplo de uso de la pantalla OLED del Entrenador
 * 
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Mostrar por la pantalla el icono por defecto.
 */

#include "EntrenadorPantallas.h"

// Declaración de instancia de las clases
EntrenadorPantallas miEntrenadorPantallas;

// Inicialización del sketch
void setup() {

    // Inicializamos la pantalla y mostramos el icono
    miEntrenadorPantallas.inicializarOLED();
    miEntrenadorPantallas.oled.display();

}

// Bucle principal del sketch
void loop() {

}
