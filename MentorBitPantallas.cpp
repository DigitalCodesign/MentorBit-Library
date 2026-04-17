/*
 * MentorBitPantallas.cpp - Librería del módulo Pantallas para MentorBit Arduino
 *
 * Creado el 13/09/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Definición de la clase MentorBitPantallas,
 * referida al MentorBit compatible con Arduino y el módulo de pantallas.
 */

#include "MentorBitPantallas.h"

#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETDDRAMADDR 0x80
#define LCD_SETCGRAMADDR 0x40

#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSOROFF 0x00
#define LCD_BLINKOFF 0x00
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_5x8DOTS 0x00

#define En B00000100
#define Rw B00000010
#define Rs B00000001

/*
 * Constructor de la clase para el controlador de la pantalla LCD.
 * 
 * Devuelve una instancia de la clase MentorBitLCD que permite el control directo de la LCD.
 */
MentorBitLCD::MentorBitLCD(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
{

    _addr = lcd_addr;
    _cols = lcd_cols;
    _rows = lcd_rows;
    _backlight_value = 0x08;

}

/*
 * Función para inicializar la pantalla LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::begin()
{

    Wire.begin();
    _display_control = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    // Secuencia de inicialización
    delay(50); 
    _expanderWrite(_backlight_value);
    delay(1000);
    // Forzar modo 4 bits
    _write4bits(0x03 << 4);
    delayMicroseconds(4500); 
    _write4bits(0x03 << 4);
    delayMicroseconds(4500); 
    _write4bits(0x03 << 4);
    delayMicroseconds(150);
    _write4bits(0x02 << 4);
    // Configuración final
    _command(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);
    _command(LCD_DISPLAYCONTROL | _display_control);
    clear();
    _command(LCD_ENTRYMODESET | 0x02);

}

/*
 * Función para limpiar y vaciar la pantalla LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::clear()
{
    _command(LCD_CLEARDISPLAY);
    delayMicroseconds(2000);
}

/*
 * Función para posicionar el cursor en la posición inicial (columna 0, fila 0).
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::home()
{
    _command(LCD_RETURNHOME);
    delayMicroseconds(2000); 
}

/*
 * Función para establecer la posición del cursor en la pantalla.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::setCursor(uint8_t col, uint8_t row)
{
    int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
    if (row > _rows) row = _rows - 1;
    _command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

/*
 * Función para encender la retroiluminación (luz de fondo) de la pantalla LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::backlight()
{
    _backlight_value = 0x08;
    _expanderWrite(0);
}

/*
 * Función para apagar la retroiluminación (luz de fondo) de la pantalla LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::noBacklight()
{
    _backlight_value = 0x00;
    _expanderWrite(0);
}

/*
 * Función para limpiar la fila y centrar el texto automáticamente.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::imprimirCentrado(uint8_t fila, String texto)
{
    // Limpiamos la fila sobrescribiéndola con espacios
    setCursor(0, fila);
    for (uint8_t i = 0; i < _cols; i++) print(" ");
    // Recortamos si el texto es más largo que la pantalla
    if (texto.length() > _cols) texto = texto.substring(0, _cols);
    // Calculamos la posición inicial para centrar
    uint8_t pos_x = (_cols - texto.length()) / 2;
    setCursor(pos_x, fila);
    print(texto);
}

/*
 * Dibuja una barra en la fila elegida, dado un porcentaje (0-100)
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::dibujarBarra(uint8_t fila, uint8_t porcentaje)
{
    // Aseguramos límites
    if (porcentaje > 100) porcentaje = 100;
    // Calculamos cuántos bloques sólidos corresponden a ese porcentaje
    // Mapeamos de 0-100% al número de columnas de la LCD (ej. 16)
    uint8_t bloques_llenos = (porcentaje * _cols) / 100;
    setCursor(0, fila);
    // Dibujamos la barra
    for (uint8_t i = 0; i < _cols; i++)
    {
        if (i < bloques_llenos) write(0xFF); // Carácter de bloque sólido
        else print("-");  // Relleno vacío
    }
}

/**
 * Función base para crear caracteres.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::_crearCaracter(uint8_t ubicacion, uint8_t mapa_bits[])
{
    ubicacion &= 0x7; // Solo tenemos 8 posiciones (0-7)
    _command(LCD_SETCGRAMADDR | (ubicacion << 3));
    for (int i = 0; i < 8; i++) _send(mapa_bits[i], Rs); // Enviamos como dato
}

/**
 * Carga un icono predefinido en una de las 8 ranuras de memoria de la LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::cargarIcono(IconoLCD icono, uint8_t ubicacion_memoria)
{
    // Limitamos la ubicación a 0-7 para no desbordar la memoria de la LCD
    ubicacion_memoria &= 0x07; 
    // --- MAPAS DE BITS (5x8 píxeles) ---
    uint8_t corazon[8]    = {0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00};
    uint8_t sonrisa[8]    = {0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};
    // Energía
    uint8_t bat_baja[8]   = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x00};
    uint8_t bat_media[8]  = {0x0E, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
    uint8_t bat_llena[8]  = {0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
    // Sensores
    uint8_t termometro[8] = {0x04, 0x0A, 0x0A, 0x0A, 0x0E, 0x1F, 0x1F, 0x0E};
    uint8_t gota[8]       = {0x04, 0x04, 0x0A, 0x0A, 0x11, 0x11, 0x11, 0x0E};
    uint8_t reloj[8]      = {0x1F, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x1F, 0x00};
    // Sistemas y UI
    uint8_t wifi[8]       = {0x00, 0x0E, 0x11, 0x04, 0x0A, 0x00, 0x04, 0x00};
    uint8_t campana[8]    = {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00};
    uint8_t check[8]      = {0x00, 0x00, 0x01, 0x03, 0x16, 0x1C, 0x08, 0x00};
    uint8_t cruz[8]       = {0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00};
    uint8_t flecha_d[8]   = {0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00, 0x00};
    uint8_t flecha_i[8]   = {0x00, 0x04, 0x08, 0x1F, 0x08, 0x04, 0x00, 0x00};
    // --- ASIGNACIÓN ---
    switch (icono) {
        case CORAZON:       _crearCaracter(ubicacion_memoria, corazon);    break;
        case SONRISA:       _crearCaracter(ubicacion_memoria, sonrisa);    break;
        case BATERIA_BAJA:  _crearCaracter(ubicacion_memoria, bat_baja);   break;
        case BATERIA_MEDIA: _crearCaracter(ubicacion_memoria, bat_media);  break;
        case BATERIA_LLENA: _crearCaracter(ubicacion_memoria, bat_llena);  break;
        case TEMPERATURA:   _crearCaracter(ubicacion_memoria, termometro); break;
        case GOTA_AGUA:     _crearCaracter(ubicacion_memoria, gota);       break;
        case RELOJ:         _crearCaracter(ubicacion_memoria, reloj);      break;
        case WIFI:          _crearCaracter(ubicacion_memoria, wifi);       break;
        case CAMPANA:       _crearCaracter(ubicacion_memoria, campana);    break;
        case CHECK_OK:      _crearCaracter(ubicacion_memoria, check);      break;
        case CRUZ_NOK:      _crearCaracter(ubicacion_memoria, cruz);       break;
        case FLECHA_DER:    _crearCaracter(ubicacion_memoria, flecha_d);   break;
        case FLECHA_IZQ:    _crearCaracter(ubicacion_memoria, flecha_i);   break;
    }
}

/*
 * Función para imprimir un único carácter en la pantalla (requerido por la clase Print).
 * 
 * Devuelve la cantidad de bytes escritos.
 */
size_t MentorBitLCD::write(uint8_t value)
{
    _send(value, Rs);
    return 1;
}

/*
 * Función interna para enviar un comando de configuración al controlador LCD.
 * 
 * No devuelve ningún valor.
 */
inline void MentorBitLCD::_command(uint8_t value)
{
    _send(value, 0);
}

/*
 * Función interna para enviar un byte al LCD, dividiéndolo en dos partes de 4 bits.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::_send(uint8_t value, uint8_t mode)
{
    uint8_t highnib = value & 0xF0;
    uint8_t lownib  = (value << 4) & 0xF0;
    _write4bits((highnib) | mode);
    _write4bits((lownib) | mode);
}

/*
 * Función interna para preparar 4 bits de datos y generar el pulso de habilitación.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::_write4bits(uint8_t value)
{
    _expanderWrite(value);
    _pulseEnable(value);
}

/*
 * Función interna para transmitir un byte físicamente al expansor I2C a través del bus I2C.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::_expanderWrite(uint8_t _data)
{                                        
    Wire.beginTransmission(_addr);
    Wire.write((int)(_data | _backlight_value));
    Wire.endTransmission();   
}

/*
 * Función interna para generar un pulso en el pin de habilitación y fijar los datos en el LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitLCD::_pulseEnable(uint8_t _data)
{
    _expanderWrite(_data | En);
    delayMicroseconds(1);
    _expanderWrite(_data & ~En);
    delayMicroseconds(50);
}

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
    , oled(128, 64, &Wire, -1)
    , lcdDirection(0x3F)
    , oledDirection(0x3C)
{}

/*
 * Función para inicializar la pantalla LCD.
 * 
 * No devuelve ningún valor.
 */
void MentorBitPantallas::inicializarLCD()
{

    lcd.begin();
    lcd.backlight();

}

/*
 * Función para inicializar la pantalla OLED.
 * 
 * No devuelve ningún valor.
 */
void MentorBitPantallas::inicializarOLED()
{

    oled.begin(SSD1306_SWITCHCAPVCC, oledDirection);

}