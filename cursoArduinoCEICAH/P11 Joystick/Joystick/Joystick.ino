// pines del Joystick en Arduino
const int x_pin = 0; //A0
const int y_pin = 1; //A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  // convertir de valores a grados
  float ejeX = analogRead(x_pin);   //eje x
  ejeX = map(ejeX, 0, 1023, 0, 180);  

  float ejeY = analogRead(y_pin);   //eje y
  ejeY = map(ejeY, 0, 1023, 0, 180);  

  
  Serial.print("X-eje: ");
  Serial.print(ejeX); //impresión del eje x
  Serial.print(" ");
  Serial.print("Y-eje: ");
  Serial.println(ejeY); //impresión del eje y
  Serial.print("\n");
  delay(300);
}
