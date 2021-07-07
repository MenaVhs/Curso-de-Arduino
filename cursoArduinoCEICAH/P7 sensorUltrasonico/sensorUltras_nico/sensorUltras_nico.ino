int trig = 12;
int echo = 13;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT); //ENVIAR INFORMACIÓN
  pinMode(echo, INPUT); // RECIBIR INFORMACIÓN
}

void loop() {
  long tiempo;
  long distancia;

  //Enviar una onda de sonido
  digitalWrite(trig, LOW); //apagar Trig
  delayMicroseconds(4);    //disparo límpio para enviar una onda sónica límpia
  digitalWrite(trig, HIGH);//lo prendemos por 10 microseg
  delayMicroseconds(10);
  digitalWrite(trig, LOW);//lo apagamos para que envíe 8 pulsos

  //activar el conteo para saber en cuánto tiempo regresa la señal
  tiempo = pulseIn(echo, HIGH); //activamos a Echo, e inicia a contar en el momento que se activa echo

  //Velocidad de la onda 343 (m/s) = 1/29.2 (cm/us) 
  distancia = tiempo / (29*2);  //Como usamos variable long, se cierra 29.2 a 29

  Serial.println(distancia);
  delay(50); //es recomendable usar este tiempo de lectura
}
