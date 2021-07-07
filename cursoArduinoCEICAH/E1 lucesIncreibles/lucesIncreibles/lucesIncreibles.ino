int pinArray[] = {2, 3, 4}; //Array que guarda el número de pines, sintaxis 0, 1, 2 = 2, 3, 4
int pinCount = 3;           //Contantes que indica la cantidad de pines totales
int count = 0;              //Cuenta que inicia desde cero
int timer1 = 1000;          //Tiempo en micro segundo 1000 = 1s
int timer2 = 500;

void setup(){
  for (count = 0; count < pinCount; count++) {
  pinMode(pinArray[count], OUTPUT);
  }
}
void loop() {
  for (count = 0;count < pinCount; count++) {
  digitalWrite(pinArray[count], HIGH);
  delay(timer1);
  digitalWrite(pinArray[count], LOW);
  delay(timer2);
  }
}
