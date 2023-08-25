/**
 * LedDRgb.ino - Ejemplo de uso de LED RGB del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Encendido secuencial y combinado de los colores del RGB del Entrenador
 * utilizando la librería.
 */

// Definición de pines donde están conectados los LEDs (Cambiar a librería)
const uint8_t rgbRojo = 8;
const uint8_t rgbVerde = 9;
const uint8_t rgbAzul = 10;

// Inicialización del sketch
void setup() {

    // Definición de pines como salida
    pinMode(rgbRojo, OUTPUT);
    pinMode(rgbVerde, OUTPUT);
    pinMode(rgbAzul, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(rgbRojo, LOW);
    digitalWrite(rgbVerde, LOW);
    digitalWrite(rgbAzul, LOW);

}

// Bucle principal del sketch
void loop() {

    // Encendemos el color rojo
    digitalWrite(rgbRojo, HIGH);
    digitalWrite(rgbVerde, LOW);
    digitalWrite(rgbAzul, LOW);
    delay(500);

    // Encendemos el color rojo y el verde
    digitalWrite(rgbRojo, HIGH);
    digitalWrite(rgbVerde, HIGH);
    digitalWrite(rgbAzul, LOW);
    delay(500);

    // Encendemos el color verde
    digitalWrite(rgbRojo, LOW);
    digitalWrite(rgbVerde, HIGH);
    digitalWrite(rgbAzul, LOW);
    delay(500);

    // Encendemos el color verde y el azul
    digitalWrite(rgbRojo, LOW);
    digitalWrite(rgbVerde, HIGH);
    digitalWrite(rgbAzul, HIGH);
    delay(500);

    // Encendemos el color Azul
    digitalWrite(rgbRojo, LOW);
    digitalWrite(rgbVerde, LOW);
    digitalWrite(rgbAzul, HIGH);
    delay(500);

    // Encendemos el color azul y el rojo
    digitalWrite(rgbRojo, HIGH);
    digitalWrite(rgbVerde, LOW);
    digitalWrite(rgbAzul, HIGH);
    delay(500);

}
