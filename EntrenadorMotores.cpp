/*
 * EntrenadorMotores.cpp - Librería del módulo Motores para Entrenador Arduino
 *
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase EntrenadorMotores,
 * referida al Entrenador compatible con Arduino y el módulo de Motores.
 */

#include "EntrenadorMotores.h"

/*
 * Constructor de la clase para el módulo de Motores del Entrenador.
 * 
 * Devuelve una instancia de la clase EntrenadorMotores que provee los pines
 * de conexión de los motores de la placa y los puertos correspondientes.
 * También provee de los métodos necesarios para controlar los diferentes
 * motores que podemos utilizar en el Entrenador.
 * 
 * -> Servomotor
 * -> Motor DC
 * -> Motor Paso a Paso
 */

EntrenadorMotores::EntrenadorMotores()
    : myServo()
{

    servomotor = 3;
    enableDC = 4;
    entrada1DC = 28;
    entrada2DC = 29;
    bobina1PAP = 30;
    bobina2PAP = 31;
    bobina3PAP = 32;
    bobina4PAP = 33;

    pinMode(enableDC, OUTPUT);
    pinMode(entrada1DC, OUTPUT);
    pinMode(entrada2DC, OUTPUT);
    pinMode(bobina1PAP, OUTPUT);
    pinMode(bobina2PAP, OUTPUT);
    pinMode(bobina3PAP, OUTPUT);
    pinMode(bobina4PAP, OUTPUT);

}

/*
 * Función para inicializar el pin del servomotor.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorMotores::inicializarServo()
{

    myServo.attach(EntrenadorMotores::servomotor);

}

/*
 * Función para mover el servomotor el número de grados dado.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorMotores::moverServo(uint16_t grados)
{

    myServo.write(grados);

}

/*
 * Función para mover el motor de corriente continua a una velocidad
 * y dirección dadas (0 un sentido, 1 el otro sentido).
 * 
 * No devuelve ningún valor.
 */
void EntrenadorMotores::moverMotorDC(uint8_t velocidad, uint8_t direccion)
{

    switch(direccion)
    {

        case 0:
            digitalWrite(entrada1DC, HIGH);
            digitalWrite(entrada2DC, LOW);
            break;

        case 1:
            digitalWrite(entrada1DC, HIGH);
            digitalWrite(entrada2DC, LOW);
            break;

        default:
            digitalWrite(entrada1DC, LOW);
            digitalWrite(entrada2DC, LOW);

    }

    analogWrite(enableDC, velocidad);

}

/*
 * Función para mover el motor paso a paso un número dado de pasos
 * en la dirección indicada (0 un sentido, 1 el otro sentido).
 * 
 * No devuelve ningún valor.
 */
void EntrenadorMotores::moverMotorPP(uint16_t pasos, uint8_t direccion)
{

    uint8_t secuencia[8][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 1}
    };

    switch (direccion)
    {

        case 0:
            for(uint16_t i = 0; i < pasos; i++)
            {
                for(uint16_t j = 0; j < 8; j++)
                {
                    digitalWrite(bobina1PAP, secuencia[j][0]);
                    digitalWrite(bobina2PAP, secuencia[j][1]);
                    digitalWrite(bobina3PAP, secuencia[j][2]);
                    digitalWrite(bobina4PAP, secuencia[j][3]);
                    delay(1);
                }
            }
            break;

        case 1:
            for(uint16_t i = 0; i < pasos; i++)
            {
                for(uint16_t j = 0; j < 8; j++)
                {
                    digitalWrite(bobina1PAP, secuencia[j][3]);
                    digitalWrite(bobina2PAP, secuencia[j][2]);
                    digitalWrite(bobina3PAP, secuencia[j][1]);
                    digitalWrite(bobina4PAP, secuencia[j][0]);
                    delay(1);
                }
            }
            break;

        default:
            digitalWrite(bobina1PAP, 0);
            digitalWrite(bobina2PAP, 0);
            digitalWrite(bobina3PAP, 0);
            digitalWrite(bobina4PAP, 0);
            break;

    }

    digitalWrite(bobina1PAP, 0);
    digitalWrite(bobina2PAP, 0);
    digitalWrite(bobina3PAP, 0);
    digitalWrite(bobina4PAP, 0);

}
