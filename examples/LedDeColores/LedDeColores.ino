/**
 * LedDeColores.ino - Ejemplo de uso de LEDs del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido secuencial de los LEDs de colores del Entrenador
 * utilizando la librería.
 */

// Definición de pines donde están conectados los LEDs
const uint8_t ledRojo = 5;
const uint8_t ledVerde = 6;
const uint8_t ledAzul = 7;

// Inicialización del sketch
void setup() {

    // Definición de pines como salida
    pinMode(ledRojo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAzul, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el LED rojo solamente y esperamos
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    delay(500);

    // Encendemos el LED verde solamente y esperamos
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    delay(500);

    // Encendemos el LED azul solamente y esperamos
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(500);

}
