/*
 * EntrenadorDataLogger.h - Librería del módulo de DataLogger (SD y RTC) para Entrenador Arduino
 *
 * Creado el 18/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorDataLogger,
 * referida al Entrenador compatible con Arduino y el módulo de SD y RTC.
 * 
 */

#ifndef EntrenadorDataLogger_h
#define EntrenadorDataLogger_h

    #include "Arduino.h"
    #include "Wire.h"
    #include "SD.h"
    #include "RTClib.h"

    class EntrenadorDataLogger
    {

        public:

            EntrenadorDataLogger();

            boolean inicializarSD();
            boolean escribirEnArchivo(String nombre, String mensaje);
            String leerDeArchivo(String nombre);

            boolean inicializarRTC();
            void ajustarHoraRTC(
                uint16_t anyo,
                uint8_t mes,
                uint8_t dia,
                uint8_t hora=0,
                uint8_t minuto=0,
                uint8_t segundo=0
            );
            void ajustarHoraRTC();
            String obtenerHoraRTC();

            uint8_t chipSelectSD;
            RTC_DS3231 rtc;

        private:

            File _dataFile;

    };

#endif
