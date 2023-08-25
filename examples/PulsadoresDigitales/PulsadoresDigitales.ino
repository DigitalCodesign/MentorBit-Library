/**
 * PulsadoresDigitales.ino - Ejemplo de uso de Pulsadores del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * 
 */

// Definición de pines digitales donde están conectados los pulsadores (Cambiar librería)
const uint8_t pulsador_pullup = 22;
const uint8_t pulsador_pulldown = 23;

// Declaración de pin donde está conectado los LED (Cambiar librería)
const uint8_t ledRojo = 5;
const uint8_t rgbRojo = 8;

// Inicialización del sketch
void setup() {

    // Definición de pines como entradas para los pulsadores y salida para los LED
    pinMode(pulsador_pullup, INPUT);
    pinMode(pulsador_pulldown, INPUT);
    pinMode(ledRojo, OUTPUT);
    pinMode(rgbRojo, OUTPUT);

    // Inicializar pin del LED apagado
    digitalWrite(ledRojo, LOW);
    digitalWrite(rgbRojo, LOW);

}

// Bucle principal del sketch
void loop() {

    // Comprobar la lectura del pulsador Pull Up en pin digital
    if(digitalRead(pulsador_pullup) == LOW)
    {

        // Encendemos el LED rojo durante un cuarto de segundo (0'25s)
        digitalWrite(ledRojo, HIGH);
        delay(250);
        digitalWrite(ledRojo, LOW);

    }

    // Comprobar la lectura del pulsador Pull Down en pin digital
    if(digitalRead(pulsador_pulldown) == HIGH)
    {

        // Encendemos el LED del RGB rojo durante un cuarto de segundo (0'25s)
        digitalWrite(rgbRojo, HIGH);
        delay(250);
        digitalWrite(rgbRojo, LOW);

    }

}

