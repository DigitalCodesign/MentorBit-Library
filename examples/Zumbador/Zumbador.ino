/**
 * Zumbador.ino - Ejemplo de uso del zumbador del Entrenador
 * 
 * Creado el 25/08/2023 por Kevin Rosa - kevin.ingenieria@digitalcodesign.com
 * 
 * Generación de tonos secuencial con el zumbador.
 */

// Definición de pines donde están conectado el zumbador
const uint8_t zumbador = 25;

// Inicialización del sketch
void setup() {

    // Definición de zumbador como salida
    pinMode(zumbador, OUTPUT);

    // Inicializar pines apagados
    digitalWrite(zumbador, LOW);

}

// Bucle principal del sketch
void loop() {

    // Bucle para generar diferentes frecuencias
    for(uint8_t i = 100 ; i < 1000 ; i =+ 100)
    {

        // Generar tono con la frecuencia dada por el bucle for
        tone(zumbador, i, 100);

    }

    delay(500);

}
