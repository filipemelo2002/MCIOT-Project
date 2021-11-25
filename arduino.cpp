#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int const PIN_GAS = A0;
int const PIN_PIEZO = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_PIEZO, OUTPUT);
  lcd.begin(16,2);
  lcd.print("Sensor de Gas");
  lcd.setCursor(0,2);
  lcd.print("inflamavel");
  
 
}

void loop()
{
  int sensorValue = analogRead(PIN_GAS);
  sensorValue = map(sensorValue, 300, 750, 0, 100);
  lcd.clear();
  lcd.home();
  lcd.print("Gas level: ");
  lcd.print(sensorValue);
  printGasLevel(sensorValue);
  delay(250);
}

void printGasLevel(int level) {
  lcd.setCursor(0,2);
  if (level >= 30 && level < 50) {
  	lcd.print("medio");
    tone(PIN_PIEZO,3000,250);
  } else if (level>=50 && level < 80) {
    lcd.print("alto");
    tone(PIN_PIEZO,3000,100);
  } else if (level >= 80) {
  	lcd.print("perigo");
    tone(PIN_PIEZO,3000, 250);
  } else {
  	lcd.print("normal");
  }
}
