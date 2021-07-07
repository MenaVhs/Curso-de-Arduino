//Prender un led con un botón con antirrebote y delay para rebote 
//de flanco de subida

int boton = 9;
int estadoActual = 0;    //Guarda el estado actual del botón (memoria)
int estadoAnterior = 0;  //Guardará el estado que tenía el botón
int salida = 0;          //Inicializamos el LED apagado, si salida vale 1 = LED prendido


void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT_PULLUP);  //declarar botón como entrada con resistencia de pull-up de 20k Ohm
  pinMode(LED_BUILTIN, OUTPUT); //led 13 como salida
}

void loop() {
  estadoActual = digitalRead(boton);  //leer el estado del pin del botón

  //Antirrebote
  if((estadoActual == HIGH) && (estadoAnterior == LOW)){ //El estadoActual está en alto y si el estado Anterior estaba en bajo
                                                         //EL hecho de que la condición también sea que estadoAnterior sea bajo es para
                                                         //asegurar el antirrebote
                                                        
    salida = 1 - salida;        //si, desde un inicio salida = 0, 1 - 0 = 1, entonces salida = 1 
    delayMicroseconds(20);      //retraso de lectura para eliminar rebote de flancos de subida
 Serial.println(salida);
  }

  estadoAnterior = estadoActual;//Actualizamos el estado anterior, si estado actual era 0, entonces anterior es 0, pero ya el 
                                //Estado actual se hizo 1.
  
  if(salida == 1){               //Si la salida es igual a 1 
    digitalWrite(LED_BUILTIN, HIGH);//pon en alto estado del LED
  }
  else{                             //sino
    digitalWrite(LED_BUILTIN, LOW); //apagamos el led
  }
}
