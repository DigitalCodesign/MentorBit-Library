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

    class MentorBitDataLogger
    {

        public:

            static const uint8_t SD_CHIP_SELECT = PIN_A6;

            MentorBitDataLogger();

            // --- Métodos específicos de la Tarjeta SD
            boolean inicializarSD();
            boolean escribirEnArchivo(String nombre_archivo, String mensaje);
            String leerDeArchivo(String nombre_archivo);
            boolean escribirLog(String nombre_archivo, String mensaje);

            // --- Métodos específicos del Reloj en Tiempo Real
            boolean inicializarRTC();
            void ajustarHoraRTC(
                uint16_t anyo, uint8_t mes, uint8_t dia,
                uint8_t hora, uint8_t minuto, uint8_t segundo=0
            );
            void ajustarHoraRTC();
            String obtenerHoraRTC(String formato="hh:mm:ss");
            boolean rtcFuncionando();

            // --- Métodos extra (NVRAM)
            void guardarDato(uint8_t direccion, uint8_t dato);
            uint8_t leerDato(uint8_t direccion);

        private:

            File _data_file;
            uint16_t _y;
            uint8_t _m, _d, _hh, _mm, _ss;
            uint8_t _rtc_address;

            uint8_t bcdToDec(uint8_t valor);
            uint8_t decToBcd(uint8_t valor);
            void _leerRTC();

    };

#endif
