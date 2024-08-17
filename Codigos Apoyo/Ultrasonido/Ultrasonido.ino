// Como usar Ultrasonido

// Definir e inicializar variables de emision y recepcion del pulso
const int trigPin = 9;
const int echoPin = 10;
// Definir variable que guard el tiempo que pasa entre la emision y la recepcion del pulso
long duration;
// Definir variable donde guardaremos la distancia calculada
int distance;

// Configuracion Inicial
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Generar pulso
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el tiempo del pulso
  duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia
  distance = duration * 0.034 / 2;

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Pausa
  delay(500);
}
