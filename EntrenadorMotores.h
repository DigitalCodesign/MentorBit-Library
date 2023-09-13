/*
 * EntrenadorMotores.h - Librería del módulo de Motores para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorMotores,
 * referida al Entrenador compatible con Arduino y el módulo de motores.
 * 
 * -> Servomotor
 * -> Motor Corriente Continua
 * -> Motor Paso a Paso
 */

#ifndef EntrenadorMotores_h
#define EntrenadorMotores_h

    #include "Arduino.h"
    #include "libraries/Servo/src/Servo.h"

    class EntrenadorMotores
    {

        public:

            EntrenadorMotores();

            void moverServo(uint8_t grados);
            void moverMotorDC(uint8_t velocidad, uint8_t direccion);
            void moverMotorPasoPaso(uint8_t pasos, uint8_t direccion);

            uint8_t servomotor;
            uint8_t enableDC;
            uint8_t entrada1DC;
            uint8_t entrada2DC;
            uint8_t bobina1PAP;
            uint8_t bobina2PAP;
            uint8_t bobina3PAP;
            uint8_t bobina4PAP;

        private:

        Servo myServo;

    };

#endif
