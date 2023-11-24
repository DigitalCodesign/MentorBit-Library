#include "Entrenador.h"
#include "EntrenadorMotores.h"
#include "EntrenadorSensores.h"
#include "EntrenadorPuertos.h"

Entrenador miEntrenador;
EntrenadorMotores misMotores;
EntrenadorPuertos misPuertos;
EntrenadorSensores misSensores;

void setup() {

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

    if(misSensores.obtenerLecturaLDR() > 100) {
        digitalWrite(misPuertos.puerto1_digital1, HIGH);
    } else {
        digitalWrite(misPuertos.puerto1_digital1, LOW);
    }

    if(misSensores.obtenerTemperaturaDHT() <= potenciometerTemperature) {
        digitalWrite(misPuertos.puerto1_digital2, HIGH);
    } else {
        digitalWrite(misPuertos.puerto1_digital2, LOW);
    }

    if(misSensores.obtenerHumedadDHT() <= potenciometerHumidity) {
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
