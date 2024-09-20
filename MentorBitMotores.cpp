/*
 * MentorBitMotores.cpp - Librería del módulo Motores para MentorBit Arduino
 *
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase MentorBitMotores,
 * referida al MentorBit compatible con Arduino y el módulo de Motores.
 */

#include <MentorBitMotores.h>

/*
 * Constructor de la clase para el módulo de Motores del MentorBit.
 * 
 * Devuelve una instancia de la clase MentorBitMotores que provee los pines
 * de conexión de los motores de la placa y los puertos correspondientes.
 * También provee de los métodos necesarios para controlar los diferentes
 * motores que podemos utilizar en el MentorBit.
 * 
 * -> Servomotor
 * -> Motor DC
 * -> Motor Paso a Paso
 */
MentorBitMotores::MentorBitMotores()
    : myServo1(), myServo2()
{

    pinMode(MOTOR_DC_EN, OUTPUT);
    pinMode(MOTOR_DC_IN_1, OUTPUT);
    pinMode(MOTOR_DC_IN_2, OUTPUT);
    pinMode(MOTOR_PAP_IN_1, OUTPUT);
    pinMode(MOTOR_PAP_IN_2, OUTPUT);
    pinMode(MOTOR_PAP_IN_3, OUTPUT);
    pinMode(MOTOR_PAP_IN_4, OUTPUT);

}

/*
 * Función para inicializar el pin del servomotor.
 * 
 * No devuelve ningún valor.
 */
void MentorBitMotores::inicializarServo(uint8_t servomotor)
{

    if(servomotor == SERVOMOTOR_1)
        myServo1.attach(servomotor);

    else if(servomotor == SERVOMOTOR_2)
        myServo2.attach(servomotor);

}

/*
 * Función para mover el servomotor el número de grados dado.
 * 
 * No devuelve ningún valor.
 */
void MentorBitMotores::moverServo(uint8_t servomotor, uint16_t grados)
{

    if(servomotor == SERVOMOTOR_1)
        myServo1.write(grados);

    else if(servomotor == SERVOMOTOR_2)
        myServo2.write(grados);

}

/*
 * Función para mover el motor de corriente continua a una velocidad
 * y dirección dadas (0 un sentido, 1 el otro sentido).
 * 
 * No devuelve ningún valor.
 */
void MentorBitMotores::moverMotorDC(uint8_t velocidad, uint8_t direccion)
{

    switch(direccion)
    {

        case 0:
            digitalWrite(MOTOR_DC_IN_1, HIGH);
            digitalWrite(MOTOR_DC_IN_2, LOW);
            break;

        case 1:
            digitalWrite(MOTOR_DC_IN_1, HIGH);
            digitalWrite(MOTOR_DC_IN_2, LOW);
            break;

        default:
            digitalWrite(MOTOR_DC_IN_1, LOW);
            digitalWrite(MOTOR_DC_IN_2, LOW);

    }

    analogWrite(MOTOR_DC_EN, velocidad);

}

/*
 * Función para mover el motor paso a paso un número dado de pasos
 * en la dirección indicada (0 un sentido, 1 el otro sentido).
 * 
 * No devuelve ningún valor.
 */
void MentorBitMotores::moverMotorPP(uint16_t pasos, uint8_t direccion)
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
                    digitalWrite(MOTOR_PAP_IN_1, secuencia[j][0]);
                    digitalWrite(MOTOR_PAP_IN_2, secuencia[j][1]);
                    digitalWrite(MOTOR_PAP_IN_3, secuencia[j][2]);
                    digitalWrite(MOTOR_PAP_IN_4, secuencia[j][3]);
                    delay(1);
                }
            }
            break;

        case 1:
            for(uint16_t i = 0; i < pasos; i++)
            {
                for(uint16_t j = 0; j < 8; j++)
                {
                    digitalWrite(MOTOR_PAP_IN_1, secuencia[j][3]);
                    digitalWrite(MOTOR_PAP_IN_2, secuencia[j][2]);
                    digitalWrite(MOTOR_PAP_IN_3, secuencia[j][1]);
                    digitalWrite(MOTOR_PAP_IN_4, secuencia[j][0]);
                    delay(1);
                }
            }
            break;

        default:
            digitalWrite(MOTOR_PAP_IN_1, 0);
            digitalWrite(MOTOR_PAP_IN_2, 0);
            digitalWrite(MOTOR_PAP_IN_3, 0);
            digitalWrite(MOTOR_PAP_IN_4, 0);
            break;

    }

    digitalWrite(MOTOR_PAP_IN_1, 0);
    digitalWrite(MOTOR_PAP_IN_2, 0);
    digitalWrite(MOTOR_PAP_IN_3, 0);
    digitalWrite(MOTOR_PAP_IN_4, 0);

}
