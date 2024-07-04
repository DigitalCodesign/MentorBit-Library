/*
 * MentorBitMotores.h - Librería del módulo de Motores para MentorBit Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase MentorBitMotores,
 * referida al MentorBit compatible con Arduino y el módulo de motores.
 * 
 * -> Servomotor
 * -> Motor Corriente Continua
 * -> Motor Paso a Paso
 */

#ifndef MentorBitMotores_h
#define MentorBitMotores_h

    #include "Arduino.h"
    #include "Servo.h"

    class MentorBitMotores
    {

        public:

            MentorBitMotores();

            void inicializarServo();
            void moverServo(uint16_t grados);
            void moverMotorDC(uint8_t velocidad, uint8_t direccion);
            void moverMotorPP(uint16_t pasos, uint8_t direccion);

            uint16_t servomotor;
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
