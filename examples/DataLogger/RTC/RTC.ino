/**
 * RTC.ino - Ejemplo de uso de la RTC del Entrenador
 * 
 * Creado el 19/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Establecer la hora manualmente y automáticamente para luego obtener dicha
 * hora para comprobar el ajuste del reloj.
 */

#include <EntrenadorDataLogger.h>

// Declaración de instancia de la clase
EntrenadorDataLogger miDataLogger;

// Inicialización del sketch
void setup() {

    // Inicializar comunicaciones Seriales
    Serial.begin(9600);

    // Inicializar RTC
    miDataLogger.inicializarRTC();

    // Ajustar la hora a una dada y mostrarla por pantalla
    miDataLogger.ajustarHoraRTC(2023, 5, 13);
    Serial.println(miDataLogger.obtenerHoraRTC());

    // Ajustar la hora automáticamente a la del sistema y mostrarla por pantalla
    miDataLogger.ajustarHoraRTC();
    Serial.println(miDataLogger.obtenerHoraRTC());

}

void loop() {}
