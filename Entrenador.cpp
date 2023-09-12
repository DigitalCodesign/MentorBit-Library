/*
 * Entrenador.cpp - Librería base para Entrenador Arduino
 *
 * Creado el 24/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase base Entrenador,
 * referida al Entrenador compatible con Arduino.
 */

#include "Entrenador.h"

/*
 * Constructor de la clase base del Entrenador.
 *
 * Devuelve una instancia de la clase Entrenador que provee los pines de conexión
 * de los elementos básicos de la placa.
 * 
 * -> LED de colores
 * -> LED RGB
 * -> Pulsadores
 * -> Zumbador
 * -> Potenciómetro
 */
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

    pinMode(ledRojo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAzul, OUTPUT);
    pinMode(rgbRojo, OUTPUT);
    pinMode(rgbVerde, OUTPUT);
    pinMode(rgbAzul, OUTPUT);
    pinMode(pulsadorPullUpDigital, INPUT);
    pinMode(pulsadorPullDownDigital, INPUT);
    pinMode(zumbador, OUTPUT);
    pinMode(potenciometro, INPUT);
    pinMode(pulsadorPullDownAnalogico, INPUT);
    pinMode(pulsadorPullUpAnalogico, INPUT);

}
