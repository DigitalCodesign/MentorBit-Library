/*
 * MentorBitPuertos.cpp - Librería de los puertos genéricos para MentorBit Arduino
 *
 * Creado el 27/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase base MentorBitPuertos, referida a
 * los puertos genéricos del MentorBit compatible con Arduino.
 */

#include "MentorBitPuertos.h"

/*
 * Constructor de la clase para puertos genéricos del MentorBit.
 *
 * Devuelve una instancia de la clase MentorBitPuertos que provee los pines de conexión
 * de los conectores de los puertos.
 * 
 * -> Puerto genérico 1
 * -> Puerto genérico 2
 * -> Puerto genérico 3
 */
MentorBitPuertos::MentorBitPuertos() {}

/**
 * 
 */
void MentorBitPuertos::conectar(uint8_t port, MentorPort& module) {

    MentorPort::Port module_port;

    switch (port)
    {

        case MentorBitPuertos::PUERTO_MODULO_1:
            module_port.type = 'm';
            module_port.location = port;
            module_port.gpios[0] = MentorBitPuertos::PUERTO_MODULO_1_ANALOGICO;
            module_port.gpios[1] = MentorBitPuertos::PUERTO_MODULO_1_DIGITAL;
            module.configPort(module_port);
            break;

        case MentorBitPuertos::PUERTO_MODULO_2:
            module_port.type = 'm';
            module_port.location = port;
            module_port.gpios[0] = MentorBitPuertos::PUERTO_MODULO_2_ANALOGICO;
            module_port.gpios[1] = MentorBitPuertos::PUERTO_MODULO_2_DIGITAL;
            module.configPort(module_port);
            break;

        case MentorBitPuertos::PUERTO_GENERICO_1:
            module_port.type = 'g';
            module_port.location = port;
            module_port.gpios[0] = MentorBitPuertos::PUERTO_GENERICO_1_DIGITAL_1;
            module_port.gpios[1] = MentorBitPuertos::PUERTO_GENERICO_1_DIGITAL_2;
            module_port.gpios[2] = MentorBitPuertos::PUERTO_GENERICO_1_DIGITAL_3;
            module_port.gpios[3] = MentorBitPuertos::PUERTO_GENERICO_1_DIGITAL_4;
            module_port.gpios[4] = MentorBitPuertos::PUERTO_GENERICO_1_DIGITAL_5;
            module_port.gpios[5] = MentorBitPuertos::PUERTO_GENERICO_1_DIGITAL_6;
            module_port.gpios[6] = MentorBitPuertos::PUERTO_GENERICO_1_ANALOG_1;
            module_port.gpios[7] = MentorBitPuertos::PUERTO_GENERICO_1_ANALOG_2;
            module.configPort(module_port);
            break;

        case MentorBitPuertos::PUERTO_GENERICO_2:
            module_port.type = 'g';
            module_port.location = port;
            module_port.gpios[0] = MentorBitPuertos::PUERTO_GENERICO_2_DIGITAL_1;
            module_port.gpios[1] = MentorBitPuertos::PUERTO_GENERICO_2_DIGITAL_2;
            module_port.gpios[2] = MentorBitPuertos::PUERTO_GENERICO_2_DIGITAL_3;
            module_port.gpios[3] = MentorBitPuertos::PUERTO_GENERICO_2_DIGITAL_4;
            module_port.gpios[4] = MentorBitPuertos::PUERTO_GENERICO_2_DIGITAL_5;
            module_port.gpios[5] = MentorBitPuertos::PUERTO_GENERICO_2_DIGITAL_6;
            module_port.gpios[6] = MentorBitPuertos::PUERTO_GENERICO_2_ANALOG_1;
            module_port.gpios[7] = MentorBitPuertos::PUERTO_GENERICO_2_ANALOG_2;
            module.configPort(module_port);
            break;

        case MentorBitPuertos::PUERTO_GENERICO_3:
            module_port.type = 'g';
            module_port.location = port;
            module_port.gpios[0] = MentorBitPuertos::PUERTO_GENERICO_3_DIGITAL_1;
            module_port.gpios[1] = MentorBitPuertos::PUERTO_GENERICO_3_DIGITAL_2;
            module_port.gpios[2] = MentorBitPuertos::PUERTO_GENERICO_3_DIGITAL_3;
            module_port.gpios[3] = MentorBitPuertos::PUERTO_GENERICO_3_DIGITAL_4;
            module_port.gpios[4] = MentorBitPuertos::PUERTO_GENERICO_3_DIGITAL_5;
            module_port.gpios[5] = MentorBitPuertos::PUERTO_GENERICO_3_DIGITAL_6;
            module_port.gpios[6] = MentorBitPuertos::PUERTO_GENERICO_3_ANALOG_1;
            module_port.gpios[7] = MentorBitPuertos::PUERTO_GENERICO_3_ANALOG_2;
            module.configPort(module_port);
            break;

        default:
            break;

    }

}
