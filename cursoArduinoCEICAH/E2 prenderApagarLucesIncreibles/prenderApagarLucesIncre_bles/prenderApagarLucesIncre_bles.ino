
//Variables globales
int count = 0;              //Cuenta que inicia desde cero
 //LEDs
int pinArray[] = {2, 3, 4}; //Array que guarda el número de pines, sintaxis 0, 1, 2 = 2, 3, 4
int pinCount = 3;           //Contantes que indica la cantidad de pines totales
//Botón
int boton = 9;
int estadoActual = 0;    //Guarda el estado actual del botón (memoria)
int estadoAnterior = 0;  //Guardará el estado que tenía el botón
int salida = 0;          //Inicializamos el LED apagado, si salida vale 1 = LED prendido

void setup(){
  Serial.begin(9600);
  Serial.println("Presionar una vez el botón para prender");
  Serial.println("\t");
  Serial.println("Presionar el botón por dos segundos para apagar");
  
  pinMode(boton, INPUT);  //declarar botón como entrada
  for (count = 0; count < pinCount; count++) {
  pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
   estadoActual = digitalRead(boton);  //leer el estado del pin del botón
  //Antirrebote
  if((estadoActual == HIGH) && (estadoAnterior == LOW)){
    salida = 1 - salida;        //si, desde un inicio salida = 0, 1 - 0 = 1, entonces salida = 1 7
    delayMicroseconds(20);      //retraso de lectura para eliminar rebote de flancos de subida  
    Serial.print('\t');
  } 
    estadoAnterior = estadoActual;
                   
  if(salida == 1){
     prenderLEDs();
    }
    
  if(salida == 0){
      apagarLEDs();  
  }
}

void prenderLEDs(){

    int timer1 = 200;          //Tiempo en micro segundo 1000 = 1s
    int timer2 = 200;
    if(estadoActual != estadoActual){
     salida = 0;
    }
    for (count = 0;count < pinCount; count++) {
    digitalWrite(pinArray[count], HIGH);
    delay(timer1);
    digitalWrite(pinArray[count], LOW);
    delay(timer2);
    }
}

void apagarLEDs(){
  for (count = 0;count < pinCount; count++) {
    digitalWrite(pinArray[count],LOW);
    }
}
