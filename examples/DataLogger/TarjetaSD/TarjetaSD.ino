/**
 * TarjetaSD.ino - Ejemplo de uso de la Tarjeta SD del Entrenador
 * 
 * Creado el 18/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Escribir un texto a un archivo de la tarjeta y leer luego el mismo contenido.
 */

#include <EntrenadorDataLogger.h>

// Declaración de instancia de la clase
EntrenadorDataLogger miDataLogger;

// Inicialización del sketch
void setup() {

    // Inicializar comunicaciones Seriales
    Serial.begin(9600);

    // Inicializar tarjeta SD
    if(miDataLogger.inicializarSD()) {

        Serial.println("Tarjeta inicializada correctamente.");
        Serial.println("Escribiendo a la tarjeta...");

        // Escribir el mensaje a un archivo
        miDataLogger.escribirEnArchivo("Prueba.txt", "Prueba del Entrenador.");
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
