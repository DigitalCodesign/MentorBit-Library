/*
 * EntrenadorMotores.h - Librería del módulo de Motores para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorMotores,
 * referida al Entrenador compatible con Arduino y el módulo de motores.
 * 
 * -> DHT
 * -> MQ
 * -> HC-SR04
 * -> DS18B20
 * -> LDR
 */

#ifndef EntrenadorMotores_h
#define EntrenadorMotores_h

    #include "Arduino.h"

    class EntrenadorMotores
    {

        public:

            EntrenadorMotores();

            moverServo(uint8_t grados);
            moverMotorDC(uint8_t velocidad, uint8_t direccion);
            moverMotorPasoPaso(uint8_t pasos, uint8_t direccion);

        private:

            uint8_t _servomotor;
            uint8_t _enableDC;
            uint8_t _entrada1DC;
            uint8_t _entrada2DC;
            uint8_t _bobina1PAP;
            uint8_t _bobina2PAP;
            uint8_t _bobina3PAP;
            uint8_t _bobina4PAP;

    }