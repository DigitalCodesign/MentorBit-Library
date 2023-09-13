/*
 * EntrenadorPantallas.h - Librería del módulo de Pantallas para Entrenador Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase EntrenadorPantallas,
 * referida al Entrenador compatible con Arduino y el módulo de pantallas.
 * 
 */

#ifndef EntrenadorPantallas_h
#define EntrenadorPantallas_h

    #include "Arduino.h"
    #include "Wire.h"
    #include "LiquidCrystal_I2C.h"

    class EntrenadorPantallas
    {

        public:

            EntrenadorPantallas();

            void initLCD();

        private:

            LiquidCrystal_I2C lcd;

    }