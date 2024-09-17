/*
 * MentorBitDataLogger.h - Librería del módulo de DataLogger (SD y RTC) para MentorBit Arduino
 *
 * Creado el 18/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase MentorBitDataLogger,
 * referida al MentorBit compatible con Arduino y el módulo de SD y RTC.
 * 
 */

#ifndef MentorBitDataLogger_h
#define MentorBitDataLogger_h

    #include "Arduino.h"
    #include "Wire.h"
    #include "SD.h"
    #include "RTClib.h"

    #define SD_CHIP_SELECT PIN_A6

    class MentorBitDataLogger
    {

        public:

            MentorBitDataLogger();

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

            RTC_DS1307 rtc;

        private:

            File _dataFile;

    };

#endif
