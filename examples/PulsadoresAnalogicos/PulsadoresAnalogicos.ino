/**
 * PulsadoresAnalogicos.ino - Ejemplo de uso de Pulsadores del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * 
 */

// Definición de pines analogicos donde están conectados los pulsadores (Cambiar librería)
const uint8_t pulsador_pulldown = PIN_A2;
const uint8_t pulsador_pullup = PIN_A3;

// Declaración de pin donde están conectados los LED (Cambiar librería)
const uint8_t ledRojo = 5;
const uint8_t rgbRojo = 8;

// Inicialización del sketch
void setup() {

    // Definición de pines como salida para los LED
    pinMode(ledRojo, OUTPUT);
    pinMode(rgbRojo, OUTPUT);

    // Inicializar pin de los LED apagado
    digitalWrite(ledRojo, LOW);
    digitalWrite(rgbRojo, LOW);

}

// Bucle principal del sketch
void loop() {

    // Comprobar la lectura del pulsador Pull Up en pin analogico
    if(analogRead(pulsador_pullup) < 500)
    {

        // Encendemos el LED rojo durante un cuarto de segundo (0'25s)
        digitalWrite(ledRojo, HIGH);
        delay(250);
        digitalWrite(ledRojo, LOW);

    }

    // Comprobar la lectura del pulsador Pull Down en pin analogico
    if(analogRead(pulsador_pulldown) > 500)
    {

        // Encendemos el LED RGB rojo durante un cuarto de segundo (0'25s)
        digitalWrite(rgbRojo, HIGH);
        delay(250);
        digitalWrite(rgbRojo, LOW);

    }

}

