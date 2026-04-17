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
    #include "Print.h"
    #include "Adafruit_GFX.h"
    #include "Adafruit_SSD1306.h"

    class MentorBitLCD : public Print
    {

        public:

            MentorBitLCD(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows);

            enum IconoLCD {
                CORAZON = 0,
                SONRISA = 1,
                BATERIA_BAJA = 2,
                BATERIA_MEDIA = 3,
                BATERIA_LLENA = 4,
                TEMPERATURA = 5,
                GOTA_AGUA = 6,
                RELOJ = 7,
                WIFI = 8,
                CAMPANA = 9,
                CHECK_OK = 10,
                CRUZ_NOK = 11,
                FLECHA_DER = 12,
                FLECHA_IZQ = 13
            };

            void begin();
            void clear();
            void home();
            void setCursor(uint8_t col, uint8_t row);
            void backlight();
            void noBacklight();
            void imprimirCentrado(uint8_t fila, String texto);
            void dibujarBarra(uint8_t fila, uint8_t porcentaje);
            void cargarIcono(IconoLCD icono, uint8_t ubicacion_memoria);

            virtual size_t write(uint8_t);

        private:

            uint8_t _addr;
            uint8_t _cols;
            uint8_t _rows;
            uint8_t _backlight_value;
            uint8_t _display_control;

            void _send(uint8_t, uint8_t);
            void _write4bits(uint8_t);
            void _expanderWrite(uint8_t);
            void _pulseEnable(uint8_t);
            void _command(uint8_t);
            void _crearCaracter(uint8_t ubicacion, uint8_t mapa_bits[]);

    };

    class MentorBitPantallas
    {

        public:

            MentorBitPantallas();

            void inicializarLCD();
            void inicializarOLED();

            MentorBitLCD lcd;
            Adafruit_SSD1306 oled;

        private:

            uint8_t lcdDirection;
            uint8_t oledDirection;

    };

#endif