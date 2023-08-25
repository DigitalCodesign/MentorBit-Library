/**
 * Potenciometro.ino - Ejemplo de uso del potenciometro del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Ajuste de brillo de un LED con la lectura del potenciómetro.
 */

// Definición de pines donde están conectado el potenciómetro y el LED rojo
const uint8_t potenciometro = PIN_A0;
const uint8_t ledRojo = 5;

// Inicialización del sketch
void setup() {

    // Definición de LED como salida
    pinMode(ledRojo, OUTPUT);

    // Inicializar pines apagados
    analogWrite(ledRojo, 0);

}

// Bucle principal del sketch
void loop() {

    uint8_t lectura0a1023 = analogRead(potenciometro);
    float lectura0a25 = (lectura0a1023 / 1023.00) * 255;

    analogWrite(ledRojo, lectura0a255);
    delay(100);

}
