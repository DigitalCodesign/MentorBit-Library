/*
 * EntrenadorPuertos.cpp - Librería de los puertos genéricos para Entrenador Arduino
 *
 * Creado el 27/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase base EntrenadorPuertos, referida a
 * los puertos genéricos del Entrenador compatible con Arduino.
 */

#include "EntrenadorPuertos.h"

/*
 * Constructor de la clase para puertos genéricos del Entrenador.
 *
 * Devuelve una instancia de la clase EntrenadorPuertos que provee los pines de conexión
 * de los conectores de los puertos.
 * 
 * -> Puerto genérico 1
 * -> Puerto genérico 2
 * -> Puerto genérico 3
 */
EntrenadorPuertos::EntrenadorPuertos()
{

    puerto1_digital1 = 35;
    puerto1_digital2 = 36;
    puerto1_digital3 = 37;
    puerto1_digital4 = 38;
    puerto1_digital5 = 11;
    puerto1_digital6 = 12;
    puerto1_analog1 = PIN_A10;
    puerto1_analog2 = PIN_A11;

    puerto2_digital1 = 39;
    puerto2_digital2 = 40;
    puerto2_digital3 = 41;
    puerto2_digital4 = 42;
    puerto2_digital5 = 13;
    puerto2_digital6 = 44;
    puerto2_analog1 = PIN_A12;
    puerto2_analog2 = PIN_A13;

    puerto3_digital1 = 43;
    puerto3_digital2 = 47;
    puerto3_digital3 = 48;
    puerto3_digital4 = 49;
    puerto3_digital5 = 45;
    puerto3_digital6 = 46;
    puerto3_analog1 = PIN_A14;
    puerto3_analog2 = PIN_A15;

}
