// pines del Joystick en Arduino
const int SW_pin = 2;//boton
const int x_pin = 0; //A0
const int Y_pin = 1; //A1
unsigned int angulo = 88; // inicializar angulo 90 aprox
int offset = 5;  //control del offset para aumentar o decrementar el ángulo

// pin del servoMotor
#define servoPin 3                   //Pin 3

//Servomotor
#include <Servo.h>                   //Librería para servomotor
Servo servo;                         //Activar pines PWM 
int minPulse = 500;                  //1.1 segundos de pulso mínimo lo que equivale en grados equivale a 0° (apróximadamente)
int maxPulse = 2400;                 //2 segundos de pulso máximo lo que equivale en grados equivale a 180° 


void setup() {
  Serial.begin(9600);
  //Botón Joystick
  pinMode(SW_pin, INPUT_PULLUP);
  //LED 13 como salida
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(servoPin, OUTPUT);
  servo.attach(servoPin, minPulse, maxPulse); // se inicializa el servomotor con los pulsos
}

void loop() {
  // mover el servo de acuerdo al eje X
  float ejeX = analogRead(x_pin);
  ejeX = map(ejeX, 0, 1023, 0, 180);  
  
  //Posicionamiento del servo
   if(ejeX < 80){
    angulo = angulo - offset;
   }
   else if(ejeX >= 90){
    angulo = angulo + offset;
   } 
   servo.write(angulo);   //Mover el servo
   delayMicroseconds(10);
   Serial.println(ejeX);

  // botón Joystick?
   if (!digitalRead(SW_pin))
         digitalWrite(LED_BUILTIN, HIGH);
   
   else
         digitalWrite(LED_BUILTIN, LOW);
         
   delay(250);
}
