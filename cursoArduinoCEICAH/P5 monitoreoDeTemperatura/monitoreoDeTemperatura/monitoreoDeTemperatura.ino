//Monitoreo de temperatura


#include <LiquidCrystal_I2C.h>    // incluir librería de módulo I2C
// DESCARGAR LIBRERÍA:https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip

LiquidCrystal_I2C lcd(0x3f,16,2);  // crea objeto y asigna pines a los cuales se
                                   // si no sale con esta direccion, usar (0x27,16,2) || (0x20,16,2) 
                                   
int SENSOR;                        // variable almacena valor leido de entrada analogica A0
float TEMPERATURA;                 // valor de temperatura en grados centigrados
float TEMP_FIJA = 30;              //Valor fijo de temperatura 
const float TEMP_FIJA;             // valor constante para una temperatura
float SUMA;                        // valor de la suma de las 5 lecturas de temperatura

int LED = 13;                      // Luz que se prenderá si se excede de la temperatura deseada

void setup() {
  lcd.init();                      // inicializar el display
  lcd.backlight();                 // prender la luz de display
  lcd.clear();                     //limpiar display

  pinMode(LED, OUTPUT);            //LED como salida

  // entradas analógicas no requieren inicialización
}

void loop() {
  SUMA = 0;                             // valor inicial de SUMA en cero
  for (int i=0; i < 5; i++){            // bucle que lee de 5 en 5   
    SENSOR = analogRead(A0);            // lectura de entrada analogica A0
    TEMPERATURA = ((SENSOR * 5000.0) / 1023) / 10;  // lectura de entrada del SENSOR
    SUMA = TEMPERATURA + SUMA;          // suma de cada lectura de temperatura
    delay(500);                         // demora de medio seg. entre lecturas
    
    if(TEMPERATURA >= TEMP_FIJA){       // si temperatura mayor o igual a valor fijo de temperatura
      digitalWrite(LED, HIGH);          // prende LED
      lcd.display();                    // mantener prendida la luz del display
      delay(500);                       // durante 0.5 segundos
      lcd.noDisplay();                  // apagar display 
      delay(500);                       // durante 0.5 segundos
    }
    else digitalWrite(LED, LOW);
  }
  lcd.setCursor(0, 0);                  // cursor en primer fila y primer columna
  lcd.print("Temp: ");                  // escribe Temp:
  lcd.print(SUMA/5.0, 1);               // escribe valor promedio de 5 lecturas con un decimal
  lcd.print(" C");                      // imprime C de Celsius

}
