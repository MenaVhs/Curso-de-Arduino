//Declaración de pines de los LEDs
byte led1 = 2;
byte led2 = 3;
byte led3 = 4;

//Declaración del pin del potenciómetro
int pot = A0;

int ReadSerial = '0';
int brillo;

void setup() {
  //Inicializar puerto serial
  Serial.begin(9600);
  //Se declara pin del pote como entrada
  pinMode(pot, INPUT);

  //Declaración de pines de los LEDs como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  //Prender todos los LEDs desde un inicio
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);

}

void loop() {
  int leerDatosPot = analogRead(pot);
  //Transformación del valor del potenciómetro a un número de 0 a 255 que es el rango de los colores RGB
  brillo = map(leerDatosPot, 0, 1023, 0, 255);
  
  Serial.println(brillo); //impresión del valor del brillo en porcentaje de 100%
  delay(500); //lectura cada 0.5 segundos
  
  if (Serial.available() > 0){
    int readSerial = Serial.read();

    if(readSerial == '1')
      analogWrite(led1, brillo);
    
    if(readSerial == '2')
      analogWrite(led2, brillo);

    if(readSerial == '3')
      analogWrite(led3, brillo);
  }
}
