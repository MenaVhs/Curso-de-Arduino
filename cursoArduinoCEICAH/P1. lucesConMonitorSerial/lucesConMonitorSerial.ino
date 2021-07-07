//Práctica uno

int ReadSerial = '0';
byte led1 = 2;
byte led2 = 3;
byte led3 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  if (Serial.available() > 0){
    int readSerial = Serial.read();

    if(readSerial == 'a' || readSerial == 'A'){
      digitalWrite(led1, HIGH);
    } else{
      digitalWrite(led1, LOW);
    }
    if(readSerial == 'b' || readSerial == 'B'){
      digitalWrite(led2, HIGH);
    } else{
      digitalWrite(led2, LOW);
    }
    if(readSerial == 'c' || readSerial == 'C'){
      digitalWrite(led3, HIGH);
    } else{
      digitalWrite(led3, LOW);
    }
  }
}
