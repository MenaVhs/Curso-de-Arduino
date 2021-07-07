//Práctica tres: Casting de datos enteros

int numerador = 10, denominador = 3;
float res1, res2, res3; 

void setup() {
  Serial.begin(9600);
  
  res1 = numerador/denominador;
  Serial.print("Sin casting: ");
  Serial.print(res1);

  Serial.print("\t");
  
  res2 = float(numerador)/denominador;
  Serial.print("Casting numerador: ");
  Serial.print(res2);

  Serial.print("\t");
  Serial.print("\t");

  res3 = numerador/float(denominador);
  Serial.print("Casting denominador: ");
  Serial.println(res3);
}

void loop() {

}
