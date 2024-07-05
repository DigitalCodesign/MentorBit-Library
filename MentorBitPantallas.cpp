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
MentorBitPantallas::MentorBitPantallas(DisplayType screen_type)
{

    if(screen_type == LCD) display = new ScreenLCD(0x27, 16, 2);
    else if(screen_type == OLED) display = new ScreenOLED(128, 64);

}
