// Como usar IR Analogico
// definir pin analogico para sensor IR
const int irPin = A0;
// definir variable para guardar el valor del IR
int irValue;

// Configuraicon inicial
void setup() {
  Serial.begin(9600);
}

void loop() {
  // Leer y guardar valor IR
  irValue = analogRead(irPin);
  
  // Convertir el valor analógico en distancia aproximada
  int distancia = 4800 / (irValue - 20);
  
  // Imprimir la distancia en el monitor serie
  Serial.print("Distancia IR: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Pausa
  delay(500);
}
