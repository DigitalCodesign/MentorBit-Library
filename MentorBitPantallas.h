/*
 * MentorBitPantallas.h - Librería del módulo de Pantallas para MentorBit Arduino
 *
 * Creado el 07/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Declaración de atributos y métodos para la clase MentorBitPantallas,
 * referida al MentorBit compatible con Arduino y el módulo de pantallas.
 * 
 */

#ifndef MentorBitPantallas_h
#define MentorBitPantallas_h

#include "Arduino.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

enum DisplayType {LCD, OLED};

class DisplayBase {};
class MentorBitPantallas
{

    public:

        MentorBitPantallas(DisplayType screen_type);

    private:

        DisplayBase* display;

};

class ScreenLCD : public LiquidCrystal_I2C
{

    public: ScreenLCD(uint8_t lcd_addr, uint8_t lcd_rows, uint8_t lcd_cols)
        : LiquidCrystalI2C(lcd_addr, lcd_rows, lcd_cols) {}

}

class ScreenOLED : public LiquidCrystal_I2C
{

    public: ScreenOLED(
        uint8_t oled_width,
        uint8_t oled_height,
        TwoWire *twi=&Wire,
        int8_t rst_pin=-1
    ) : Adafruit_SSD1306(
        oled_width,
        oled_height,
        twi,
        rst_pin
    ) {}

    void begin() override {

        Adafruit_SSD1306::begin(SSD1306_SWITCHCAPVCC, 0x3C);

    }

}

#endif
