/*
 * MentorBitPantallas.cpp - Librería del módulo Pantallas para MentorBit Arduino
 *
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase MentorBitPantallas,
 * referida al MentorBit compatible con Arduino y el módulo de pantallas.
 */

#include "MentorBitPantallas.h"

/*
 * Constructor de la clase para el módulo de pantallas del MentorBit.
 * 
 * Devuelve una instancia de la clase MentorBitPantallas que provee las
 * direcciones de conexión de los pantallas de la placa y un objeto para
 * utilizarlas.
 * 
 * -> Pantalla LCD
 * -> Pantalla OLED
 */
MentorBitPantallas::MentorBitPantallas()
    : lcd(0x3F, 16, 2)
    , oled(-1)
{

    uint16_t lcdDirection = 0x3F;
    uint16_t oledDirection = 0x3C;

}

/*
 * Función para inicializar la pantalla LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitPantallas::inicializarLCD()
{

    MentorBitPantallas::lcd.init();

}

/*
 * Función para inicializar la pantalla OLED.
 * 
 * No devuelve ningún valor.
 */
void MentorBitPantallas::inicializarOLED()
{

    MentorBitPantallas::oled.begin(
        SSD1306_SWITCHCAPVCC,
        MentorBitPantallas::oledDirection
    );

}
