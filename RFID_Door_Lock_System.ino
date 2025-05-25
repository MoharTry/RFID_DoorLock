#include <LiquidCrystal.h>

const int entrySensor = 6;  // Pin for the entry IR sensor
const int exitSensor = 7;   // Pin for the exit IR sensor
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // LCD pin configuration

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int entryCount = 0;
int exitCount = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // Adjust these values based on your LCD configuration
  pinMode(entrySensor, INPUT);
  pinMode(exitSensor, INPUT);

  lcd.print("Visitor Counter");
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("Entry:0  Exit:0");
  delay(200);
}

void updateLCD() {
  lcd.setCursor(6, 1);
  lcd.print(entryCount);
  delay(200);
  lcd.setCursor(14, 1);
  lcd.print(exitCount);
  delay(200);
}

void loop() {
  if (digitalRead(entrySensor) == LOW) {
    delay(100);  // Debounce delay
    entryCount++;
    updateLCD();
    delay(1000);  // Wait for one second to avoid counting multiple times for a single visitor
   }

  if (digitalRead(exitSensor) == LOW) {
    delay(100);  // Debounce delay
    exitCount++;
    updateLCD();
    delay(1000);  // Wait for one second to avoid counting multiple times for a single visitor
   } 
}
