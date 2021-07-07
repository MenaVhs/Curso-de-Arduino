#define sensor A0
float val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  //No se deben inicializar pines analógicos
}

void loop() {
  val = analogRead(sensor);
  float nivel = (val*5)/660;

  if(nivel < 0.9){
    Serial.println("Sin agua");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if(nivel >= 1 && nivel < 2){
    Serial.println("Nivel de agua: bajo");
    digitalWrite(LED_BUILTIN, HIGH);
  } else digitalWrite(LED_BUILTIN, LOW); 
  
  if(nivel >= 2 && nivel < 3){
    Serial.println("Nivel de agua: medio");
  }
  else if( nivel >= 3.0){
    Serial.println("Nivel de agua: alto");
  }

  Serial.println('\t');
  Serial.println(nivel);
  delay(800);
}
