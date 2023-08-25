/*
 * Entrenador.cpp - Librería para Entrenador Arduino
 *
 * Creado el 24/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase Trainer,
 * referida al Entrenador compatible con Arduino.
 */

#include "Entrenador.h"

Entrenador::Entrenador()
{

    this->ledRojo = 5;
    this->ledVerde = 6;
    this->ledAzul = 7;
    this->rgbRojo = 8;
    this->rgbVerde = 9;
    this->rgbAzul = 10;
    this->pulsadorPullUpDigital = 22;
    this->pulsadorPullDownDigital = 23;
    this->zumbador = 25;
    this->potenciometro = PIN_A0;
    this->pulsadorPullDownAnalogico = PIN_A2;
    this->pulsadorPullUpAnalogico = PIN_A3;

}
