/*
 * EntrenadorPantallas.cpp - Librería del módulo Pantallas para Entrenador Arduino
 *
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase EntrenadorPantallas,
 * referida al Entrenador compatible con Arduino y el módulo de pantallas.
 */

#include "EntrenadorPantallas.h"

/*
 * Constructor de la clase para el módulo de pantallas del Entrenador.
 * 
 * Devuelve una instancia de la clase EntrenadorPantallas que provee las
 * direcciones de conexión de los pantallas de la placa y un objeto para
 * utilizarlas.
 * 
 * -> Pantalla LCD
 * -> Pantalla OLED
 */
EntrenadorPantallas::EntrenadorPantallas()
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
void EntrenadorPantallas::inicializarLCD()
{

    EntrenadorPantallas::lcd.init();

}

/*
 * Función para inicializar la pantalla OLED.
 * 
 * No devuelve ningún valor.
 */
void EntrenadorPantallas::inicializarOLED()
{

    EntrenadorPantallas::oled.begin(
        SSD1306_SWITCHCAPVCC,
        EntrenadorPantallas::oledDirection
    );

}
