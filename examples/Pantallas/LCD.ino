#include "EntrenadorPantallas.h"

// Declaración de instancia de las clases
EntrenadorPantallas miEntrenadorPantallas;

// Inicialización del sketch
void setup() {

    miEntrenadorPantallas.inicializarLCD();
    miEntrenadorPantallas.lcd.backlight();
    miEntrenadorPantallas.lcd.setCursor(0, 0);
    miEntrenadorPantallas.lcd.print("Hello, world!");

}

// Bucle principal del sketch
void loop() {

}
