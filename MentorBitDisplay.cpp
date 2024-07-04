/*
 * MentorBitDisplay.cpp - Librería del módulo de Display para MentorBit Arduino
 *
 * Creado el 14/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase MentorBitDisplay,
 * referida al MentorBit compatible con Arduino y el módulo de display 7 segmentos.
 * 
 */

#include "MentorBitDisplay.h"

/*
 * Constructor de la clase para el módulo de Display del MentorBit.
 * 
 * Devuelve una instancia de la clase MentorBitDisplay que provee las
 * direcciones y métodos necesarios para controlar el display 7 segmentos
 * en el MentorBit.
 */
MentorBitDisplay::MentorBitDisplay()
    : myDisplay()
{

    _dots[0] = false;
    _dots[1] = false;
    _dots[2] = false;
    _dots[3] = false;
    _displayDirection = 0x77;

}

/*
 * Función para inicializar el Driver del Display 7 segmentos.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::inicializarDisplay()
{

    myDisplay.begin(_displayDirection);

}

/*
 * Función para mostrar por Display un valor de tipo caracter.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::imprimir(char valor)
{

    myDisplay.clear();
    myDisplay.writeDigitAscii(3, valor);
    myDisplay.writeDisplay();

}

/*
 * Función para mostrar por Display un valor de tipo cadena de texto.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::imprimir(String valor)
{

    myDisplay.clear();

    if(valor.length() > 4)
    {

        valor = valor.substring(0, 4);

    }

    while(valor.endsWith("0"))
    {

        valor.remove(valor.length() - 1);

    }

    uint8_t correcionPosicion = 4 - valor.length();

    for(uint8_t i = 0; i < valor.length(); i++)
    {

        myDisplay.writeDigitAscii(i + correcionPosicion, valor[i], _dots[i]);

    }

    myDisplay.writeDisplay();
    _dots[0] = false;
    _dots[1] = false;
    _dots[2] = false;
    _dots[3] = false;

}

/*
 * Función para mostrar por Display un valor de tipo entero.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::imprimir(int valor)
{

    String valorString = String(valor);
    MentorBitDisplay::imprimir(valorString);

}

/*
 * Función para mostrar por Display un valor de tipo numérico decimal.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::imprimir(double valor)
{

    String valorString = String(valor, 3);

    uint8_t indiceComa = valorString.indexOf('.');
    uint8_t decimales = (valorString.length() - indiceComa) - 1;

    String parteEntera = valorString.substring(0, indiceComa);
    String parteDecimal = valorString.substring(indiceComa + 1);

    valorString = parteEntera + parteDecimal;

    if(valorString.length() > 4)
    {

        valorString = valorString.substring(0, 4);

    }

    _dots[indiceComa - 1] = true;
    MentorBitDisplay::imprimir(valorString);

}
