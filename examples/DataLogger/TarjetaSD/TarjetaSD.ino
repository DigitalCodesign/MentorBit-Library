/**
 * TarjetaSD.ino - Ejemplo de uso de la Tarjeta SD del MentorBit
 * 
 * Creado el 18/09/2023 por Digital Codesign - info@digitalcodesign.com
 * 
 * Escribir un texto a un archivo de la tarjeta y leer luego el mismo contenido.
 */

#include <MentorBitDataLogger.h>

// Declaración de instancia de la clase
MentorBitDataLogger miDataLogger;

// Inicialización del sketch
void setup() {

    // Inicializar comunicaciones Seriales
    Serial.begin(9600);

    // Inicializar tarjeta SD
    if(miDataLogger.inicializarSD()) {

        Serial.println("Tarjeta inicializada correctamente.");
        Serial.println("Escribiendo a la tarjeta...");

        // Escribir el mensaje a un archivo
        miDataLogger.escribirEnArchivo("Prueba.txt", "Prueba del MentorBit.");
        Serial.println("Escritura realizada. Pasando a leer contenido...");

        // Leer contenido del archivo
        String data = miDataLogger.leerDeArchivo("Prueba.txt");
        Serial.println("Contenido del archivo:\n" + data);

    }

    else {

        Serial.println("Error en la tarjeta.");

    }

}

void loop() {}
