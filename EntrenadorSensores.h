/*
 * EntrenadorSensores.h - Librería del módulo de Sensores para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorSensores,
 * referida al Entrenador compatible con Arduino y el módulo de sensores.
 * 
 * -> DHT
 * -> MQ
 * -> HC-SR04
 * -> DS18B20
 * -> LDR
 */

#ifndef EntrenadorSensores_h
#define EntrenadorSensores_h

    #include "Arduino.h"

    class EntrenadorSensores
    {

        public:

            EntrenadorSensores();

            obtenerTemperaturaDS18B20();
            obtenerTemperaturaDHT();
            obtenerHumedadDHT();
            obtenerLuzLDR();
            obtenerDistanciaUlrasonidos();

        private:



    }
