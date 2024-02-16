#include "Entrenador.h"
#include "EntrenadorMotores.h"
#include "EntrenadorSensores.h"
#include "EntrenadorPuertos.h"
#include "EntrenadorPantallas.h"

Entrenador miEntrenador;
EntrenadorMotores misMotores;
EntrenadorPuertos misPuertos;
EntrenadorSensores misSensores;
EntrenadorPantallas misPantallas;

void setup() {

    misPantallas.inicializarLCD();
    misPantallas.lcd.backlight();

    pinMode(misPuertos.puerto1_digital1, OUTPUT);
    pinMode(misPuertos.puerto1_digital2, OUTPUT);
    pinMode(misPuertos.puerto1_digital3, OUTPUT);
    pinMode(misPuertos.puerto1_digital4, OUTPUT);
    pinMode(misPuertos.puerto1_digital5, INPUT);

    digitalWrite(misPuertos.puerto1_digital1, LOW);
    digitalWrite(misPuertos.puerto1_digital2, LOW);
    digitalWrite(misPuertos.puerto1_digital3, LOW);
    digitalWrite(misPuertos.puerto1_digital4, LOW);

}

void loop() {

    const int potenciometerTemperature = map(analogRead(miEntrenador.potenciometro), 0, 1023, 0, 100);
    const int potenciometerHumidity = map(misSensores.obtenerLecturaMQ(), 0, 1023, 0, 100);
    const int temperature = misSensores.obtenerTemperaturaDHT();
    const int humidity = misSensores.obtenerHumedadDHT();
    const int luminosity = misSensores.obtenerLecturaLDR();

    misPantallas.lcd.clear();
    misPantallas.lcd.setCursor(0, 0);
    misPantallas.lcd.print("T: " + String(temperature) + "|H: " + String(humidity));
    misPantallas.lcd.setCursor(0, 1);
    misPantallas.lcd.print("t: " + String(potenciometerTemperature) + "|h: " + String(potenciometerHumidity));

    if(luminosity > 100) {
        digitalWrite(misPuertos.puerto1_digital1, HIGH);
    } else {
        digitalWrite(misPuertos.puerto1_digital1, LOW);
    }

    if(temperature <= potenciometerTemperature) {
        digitalWrite(misPuertos.puerto1_digital2, HIGH);
    } else {
        digitalWrite(misPuertos.puerto1_digital2, LOW);
    }

    if(humidity <= potenciometerHumidity) {
        digitalWrite(misPuertos.puerto1_digital3, HIGH);
    } else {
        digitalWrite(misPuertos.puerto1_digital3, LOW);
    }

    if(digitalRead(miEntrenador.pulsadorPullUpDigital) == LOW) {
        digitalWrite(misPuertos.puerto1_digital4, HIGH);
    } else {
        digitalWrite(misPuertos.puerto1_digital4, LOW);
    }

    if(digitalRead(misPuertos.puerto1_digital5) == HIGH) {
        misMotores.moverMotorDC(255, 0);
    } else {
        misMotores.moverMotorDC(0, 0);
    }

    delay(500);

}
