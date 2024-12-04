/**
 * Zumbador.ino - Ejemplo de uso del zumbador del MentorBit
 * 
 * Creado el 25/08/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Generación de tonos secuencial con el zumbador.
 */

#include <MentorBit.h>

// Declaración de instancia de la clase
MentorBit miMentorBit;

// Inicialización del sketch
void setup() {

    // Inicializar pines apagados
    digitalWrite(miMentorBit.ZUMBADOR, LOW);

}

// Bucle principal del sketch
void loop() {

    // Generar tono con diferentes frecuencias
    tone(miMentorBit.ZUMBADOR, 3000, 250);
    delay(250);
    tone(miMentorBit.ZUMBADOR, 2000, 250);
    delay(250);
    tone(miMentorBit.ZUMBADOR, 1000, 250);
    delay(2500);

}
