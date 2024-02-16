#include "EntrenadorPantallas.h"
#include "EntrenadorPuertos.h"

EntrenadorPuertos misPuertos;
EntrenadorPantallas misPantallas;

const int tiempoDeEspera = 1000;

void setup() {

    // Inicializamos la pantalla y mostramos el mensaje.
    misPantallas.inicializarLCD();
    misPantallas.lcd.backlight();

    // Establecer modo de uso de los pines
    pinMode(misPuertos.puerto1_digital1, OUTPUT);
    pinMode(misPuertos.puerto1_digital2, OUTPUT);
    pinMode(misPuertos.puerto1_digital3, OUTPUT);
    pinMode(misPuertos.puerto1_digital4, OUTPUT);
    pinMode(misPuertos.puerto1_digital5, OUTPUT);
    pinMode(misPuertos.puerto1_digital6, OUTPUT);
    pinMode(misPuertos.puerto2_digital1, OUTPUT);
    pinMode(misPuertos.puerto2_digital2, OUTPUT);
    pinMode(misPuertos.puerto2_digital3, OUTPUT);
    pinMode(misPuertos.puerto2_digital4, OUTPUT);
    pinMode(misPuertos.puerto2_digital5, OUTPUT);
    pinMode(misPuertos.puerto2_digital6, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, LOW);
    digitalWrite(misPuertos.puerto1_digital5, LOW);
    digitalWrite(misPuertos.puerto1_digital6, LOW);
    digitalWrite(misPuertos.puerto2_digital1, LOW);
    digitalWrite(misPuertos.puerto2_digital2, LOW);
    digitalWrite(misPuertos.puerto2_digital3, LOW);
    digitalWrite(misPuertos.puerto2_digital4, LOW);
    digitalWrite(misPuertos.puerto2_digital5, LOW);
    digitalWrite(misPuertos.puerto2_digital6, LOW);

}

void loop() {

    // Encendemos secuencialmente los pines digitales del Puerto 1 y Puerto 2
    // Mostramos la secuencia a su vez por la pantallas LCD

    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("123456 || 123456");
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("100000 || 100000");

    digitalWrite(misPuertos.puerto1_digital1, HIGH);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, LOW);
    digitalWrite(misPuertos.puerto1_digital5, LOW);
    digitalWrite(misPuertos.puerto1_digital6, LOW);
    digitalWrite(misPuertos.puerto2_digital1, HIGH);
    digitalWrite(misPuertos.puerto2_digital2, LOW);
    digitalWrite(misPuertos.puerto2_digital3, LOW);
    digitalWrite(misPuertos.puerto2_digital4, LOW);
    digitalWrite(misPuertos.puerto2_digital5, LOW);
    digitalWrite(misPuertos.puerto2_digital6, LOW);

    delay(tiempoDeEspera);

    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("123456 || 123456");
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("010000 || 010000");

    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, HIGH);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, LOW);
    digitalWrite(misPuertos.puerto1_digital5, LOW);
    digitalWrite(misPuertos.puerto1_digital6, LOW);
    digitalWrite(misPuertos.puerto2_digital1, LOW);
    digitalWrite(misPuertos.puerto2_digital2, HIGH);
    digitalWrite(misPuertos.puerto2_digital3, LOW);
    digitalWrite(misPuertos.puerto2_digital4, LOW);
    digitalWrite(misPuertos.puerto2_digital5, LOW);
    digitalWrite(misPuertos.puerto2_digital6, LOW);

    delay(tiempoDeEspera);

    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("123456 || 123456");
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("001000 || 001000");

    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, HIGH);
    digitalWrite(misPuertos.puerto1_digital4, LOW);
    digitalWrite(misPuertos.puerto1_digital5, LOW);
    digitalWrite(misPuertos.puerto1_digital6, LOW);
    digitalWrite(misPuertos.puerto2_digital1, LOW);
    digitalWrite(misPuertos.puerto2_digital2, LOW);
    digitalWrite(misPuertos.puerto2_digital3, HIGH);
    digitalWrite(misPuertos.puerto2_digital4, LOW);
    digitalWrite(misPuertos.puerto2_digital5, LOW);
    digitalWrite(misPuertos.puerto2_digital6, LOW);

    delay(tiempoDeEspera);

    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("123456 || 123456");
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("000100 || 000100");

    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, HIGH);
    digitalWrite(misPuertos.puerto1_digital5, LOW);
    digitalWrite(misPuertos.puerto1_digital6, LOW);
    digitalWrite(misPuertos.puerto2_digital1, LOW);
    digitalWrite(misPuertos.puerto2_digital2, LOW);
    digitalWrite(misPuertos.puerto2_digital3, LOW);
    digitalWrite(misPuertos.puerto2_digital4, HIGH);
    digitalWrite(misPuertos.puerto2_digital5, LOW);
    digitalWrite(misPuertos.puerto2_digital6, LOW);

    delay(tiempoDeEspera);

    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("123456 || 123456");
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("000010 || 000010");

    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, LOW);
    digitalWrite(misPuertos.puerto1_digital5, HIGH);
    digitalWrite(misPuertos.puerto1_digital6, LOW);
    digitalWrite(misPuertos.puerto2_digital1, LOW);
    digitalWrite(misPuertos.puerto2_digital2, LOW);
    digitalWrite(misPuertos.puerto2_digital3, LOW);
    digitalWrite(misPuertos.puerto2_digital4, LOW);
    digitalWrite(misPuertos.puerto2_digital5, HIGH);
    digitalWrite(misPuertos.puerto2_digital6, LOW);

    delay(tiempoDeEspera);

    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("123456 || 123456");
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("000001 || 000001");

    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, LOW);
    digitalWrite(misPuertos.puerto1_digital5, LOW);
    digitalWrite(misPuertos.puerto1_digital6, HIGH);
    digitalWrite(misPuertos.puerto2_digital1, LOW);
    digitalWrite(misPuertos.puerto2_digital2, LOW);
    digitalWrite(misPuertos.puerto2_digital3, LOW);
    digitalWrite(misPuertos.puerto2_digital4, LOW);
    digitalWrite(misPuertos.puerto2_digital5, LOW);
    digitalWrite(misPuertos.puerto2_digital6, HIGH);

    delay(tiempoDeEspera);

    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("123456 || 123456");
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("000000 || 000000");

    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, LOW);
    digitalWrite(misPuertos.puerto1_digital5, LOW);
    digitalWrite(misPuertos.puerto1_digital6, LOW);
    digitalWrite(misPuertos.puerto2_digital1, LOW);
    digitalWrite(misPuertos.puerto2_digital2, LOW);
    digitalWrite(misPuertos.puerto2_digital3, LOW);
    digitalWrite(misPuertos.puerto2_digital4, LOW);
    digitalWrite(misPuertos.puerto2_digital5, LOW);
    digitalWrite(misPuertos.puerto2_digital6, LOW);

    delay(tiempoDeEspera);

}
