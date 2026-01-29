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
MentorBitDisplay::MentorBitDisplay() : _display_address(0x77)
{

    for(uint8_t i = 0; i < 8; i++) _display_buffer[i] = 0x00;

}

/*
 * Función para inicializar el Driver del Display 7 segmentos.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::inicializarDisplay()
{

    // Iniciar bus I2C
    Wire.begin();
    // Iniciar Display
    Wire.beginTransmission(_display_address);
    Wire.write(0x21);
    Wire.endTransmission();
    // Establecer brillo al máximo
    Wire.beginTransmission(_display_address);
    Wire.write(0xE0 | 15);
    Wire.endTransmission();
    // Encender Display
    Wire.beginTransmission(_display_address);
    Wire.write(0x81);
    Wire.endTransmission();
    // Vaciamos el buffer y limpiamos el display
    for(uint8_t i = 0; i < 8; i++) _display_buffer[i] = 0x00;
    _writeDisplay();

}

/*
 * Función para mostrar por Display un valor de tipo cadena de texto.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::imprimir(String valor)
{

    for (uint8_t i = 0 ; i < 4 && valor[i] != '\0' ; i++)
        _display_buffer[i] = _charToSegmento(valor[i]);

    _writeDisplay();

}

/*
 * Función para mostrar por Display un valor de tipo entero.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::imprimir(int valor)
{

    if (valor < 0 || valor > 9999) return;
    char buffer[5];
    snprintf(buffer, sizeof(buffer), "%4d", valor);
    imprimir(buffer);

}

/*
 * Función para mostrar por Display un valor de tipo numérico decimal.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::imprimir(double valor)
{

    String valor_string = String(valor, 3);

    uint8_t indice_coma = valor_string.indexOf('.');
    String parte_entera = valor_string.substring(0, indice_coma);
    String parte_decimal = valor_string.substring(indice_coma + 1);

    valor_string = parte_entera + parte_decimal;

    if (valor_string.length() > 4) valor_string = valor_string.substring(0, 4);

    imprimir(valor_string.c_str());
    _display_buffer[indice_coma - 1] |= 0b10000000;
    _writeDisplay();

}

/*
 * Imprimer el valor almacenado en el buffer en el display.
 * 
 * No devuelve ningún valor.
 */
void MentorBitDisplay::_writeDisplay()
{

    Wire.beginTransmission(_display_address);
    Wire.write(0x00);

    for (uint8_t i = 0 ; i < 8 ; i++)
    {
        Wire.write(_display_buffer[i]);
        Wire.write(0x00);
    }

    Wire.endTransmission();

}

uint8_t MentorBitDisplay::_charToSegmento(char c)
{

  switch (c)
  {
    case '0': return 0b00111111;
    case '1': return 0b00000110;
    case '2': return 0b01011011;
    case '3': return 0b01001111;
    case '4': return 0b01100110;
    case '5': return 0b01101101;
    case '6': return 0b01111101;
    case '7': return 0b00000111;
    case '8': return 0b01111111;
    case '9': return 0b01101111;
    case 'A': case 'a': return 0b01110111;
    case 'B': case 'b': return 0b01111100;
    case 'C': case 'c': return 0b00111001;
    case 'D': case 'd': return 0b01011110;
    case 'E': case 'e': return 0b01111001;
    case 'F': case 'f': return 0b01110001;
    case 'G': case 'g': return 0b00111101;
    case 'H': case 'h': return 0b01110100;
    case 'I': case 'i': return 0b00000100;
    case 'J': case 'j': return 0b00011110;
    case 'L': case 'l': return 0b00111000;
    case 'N': case 'n': return 0b01010100;
    case 'O': case 'o': return 0b00111111;
    case 'P': case 'p': return 0b01110011;
    case 'Q': case 'q': return 0b01100111;
    case 'R': case 'r': return 0b01010000;
    case 'S': case 's': return 0b01101101;
    case 'T': case 't': return 0b01111000;
    case 'U': case 'u': return 0b00111110;
    case 'Y': case 'y': return 0b01101110;
    case '-': return 0b01000000;
    case '_': return 0b00001000;
    default: return 0b00000000;
  };

}
