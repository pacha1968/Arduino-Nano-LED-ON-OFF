const int ledPin = 13;  // Pin donde está conectado el LED

void setup() {
  pinMode(ledPin, OUTPUT);    // Configura el pin del LED como salida
  Serial.begin(9600);         // Inicia la comunicación serie a 9600 bps
  Serial.println("Sistema iniciado. Envíe 'ON' para encender el LED o 'OFF' para apagarlo.");
}

void loop() {
  if (Serial.available() > 0) {           // Verifica si hay datos disponibles en la entrada serie
    String command = Serial.readString(); // Lee la cadena de caracteres enviada
    command.trim();                       // Elimina cualquier espacio en blanco

    if (command.equalsIgnoreCase("ON")) {
      digitalWrite(ledPin, HIGH);         // Enciende el LED
      Serial.println("El LED está encendido.");
    } 
    else if (command.equalsIgnoreCase("OFF")) {
      digitalWrite(ledPin, LOW);          // Apaga el LED
      Serial.println("El LED está apagado.");
    } 
    else {
      Serial.println("Comando no reconocido. Use 'ON' o 'OFF'.");
    }
  }
}
