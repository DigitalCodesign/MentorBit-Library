/*
 * Entrenador.h - Librería para Entrenador Arduino
 *
 * Creado el 24/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase Trainer,
 * referida al Entrenador compatible con Arduino.
 */

#ifndef Entrenador_h
#define Entrenador_h

    #include "Arduino.h"

    class Entrenador
    {

        public:

            Entrenador();

            const uint8_t ledRojo;
            const uint8_t ledVerde;
            const uint8_t ledAzul;
            const uint8_t rgbRojo;
            const uint8_t rgbVerde;
            const uint8_t rgbAzul;
            const uint8_t pulsadorPullUpDigital;
            const uint8_t pulsadorPullDownDigital;
            const uint8_t zumbador;
            const uint8_t potenciometro;
            const uint8_t pulsadorPullDownAnalogico;
            const uint8_t pulsadorPullUpAnalogico;

    };

#endif
