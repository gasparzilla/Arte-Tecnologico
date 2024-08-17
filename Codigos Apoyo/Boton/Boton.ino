// Boton

// Definir pin digital para el boton
const int buttonPin = 2;

// Definir e inicializar variable para el valor del boton
int buttonState = 0;

// Configuracion inicial
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del boton y guardarlo en una variable
  buttonState = digitalRead(buttonPin);

  // Mostrar estado del boton en pantalla
  if (buttonState == LOW) {
    Serial.println("Botón presionado");
  } else {
    Serial.println("Botón no presionado");
  }

  delay(500);
}
