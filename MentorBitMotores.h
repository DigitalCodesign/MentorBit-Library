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

    #define SERVOMOTOR_1 11
    #define SERVOMOTOR_2 12
    #define MOTOR_DC_EN 4
    #define MOTOR_DC_IN_1 28
    #define MOTOR_DC_IN_2 29
    #define MOTOR_PAP_IN_1 30
    #define MOTOR_PAP_IN_2 31
    #define MOTOR_PAP_IN_3 32
    #define MOTOR_PAP_IN_4 33

    class MentorBitMotores
    {

        public:

            MentorBitMotores();

            void inicializarServo(uint8_t servomotor);
            void moverServo(uint8_t servomotor, uint16_t grados);
            void moverMotorDC(uint8_t velocidad, uint8_t direccion);
            void moverMotorPP(uint16_t pasos, uint8_t direccion);

        private:

            Servo myServo1;
            Servo myServo2;

    };

#endif
