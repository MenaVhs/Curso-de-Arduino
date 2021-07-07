#include "pitches.h" // https://gist.github.com/mikeputnam/2820675

#define buzzerPasivo 9

int pausaNota = 1000;
int reinicio = 2000;

 
// notes in the melody:
int melodia[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int tiempo = 500;  // 500 milisegundos
 
void setup() {
 
}
 
void loop() {  
  for (int nota = 0; nota < 8; nota++) {
    // Sonar buzzer cada 0.5s
    tone(buzzerPasivo, melodia[nota], tiempo);
     
    // Tiempo de retrado entre cada todo
    delay(pausaNota);
  }
   
  // Reinicia cada dos segundos
  delay(reinicio);
}
