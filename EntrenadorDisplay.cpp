/*
 * EntrenadorDisplay.cpp - Librería del módulo de Display para Entrenador Arduino
 *
 * Creado el 14/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase EntrenadorDisplay,
 * referida al Entrenador compatible con Arduino y el módulo de display 7 segmentos.
 * 
 */

#include "EntrenadorDisplay.h"

/*
 * Constructor de la clase para el módulo de Display del Entrenador.
 * 
 * Devuelve una instancia de la clase EntrenadorDisplay que provee las
 * direcciones y métodos necesarios para controlar el display 7 segmentos
 * en el Entrenador.
 */
EntrenadorDisplay::EntrenadorDisplay()
    : myDisplay()
{

    _dots[0] = false;
    _dots[1] = false;
    _dots[2] = false;
    _dots[3] = false;
    _displayDirection = 0x70;

}

/*
 * Función para inicializar el Driver del Display 7 segmentos.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorDisplay::inicializarDisplay()
{

    myDisplay.begin(0x70);

}

/*
 * Función para mostrar por Display un valor de tipo caracter.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorDisplay::imprimir(char valor)
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
void EntrenadorDisplay::imprimir(String valor)
{

    myDisplay.clear();

    if(valor.length() > 4)
    {

        valor = valor.substring(0, 4);

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
void EntrenadorDisplay::imprimir(int valor)
{

    String valorString = String(valor);
    EntrenadorDisplay::imprimir(valorString);

}

/*
 * Función para mostrar por Display un valor de tipo numérico decimal.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorDisplay::imprimir(double valor)
{

    String valorString = String(valor, 3);
    uint8_t indiceComa = valorString.indexOf('.');
    uint8_t decimales = (valorString.length() - indiceComa) - 1;
    int valorInt = (int)round(valor * pow(10, decimales));
    valorString = String(valorInt);

    if(valorString.length() > 5)
    {

        valorString = valorString.substring(0, 5);

    }

    if(valor < 1.0)
    {

        valorString = "0" + valorString;

    }

    _dots[indiceComa - 1] = true;
    EntrenadorDisplay::imprimir(valorString);

}
