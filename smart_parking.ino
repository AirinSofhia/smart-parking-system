#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define IR_ENTRY 2
#define IR_EXIT 3

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gate;

int carCount = 0;
const int maxSlots = 5;

void setup() {
  lcd.init();
  lcd.backlight();
  gate.attach(9);
  
  pinMode(IR_ENTRY, INPUT);
  pinMode(IR_EXIT, INPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");
  lcd.setCursor(0, 1);
  lcd.print("Available: ");
  lcd.print(maxSlots);
  delay(2000);
  lcd.clear();
}

void loop() {
  int entrySensor = digitalRead(IR_ENTRY);
  int exitSensor = digitalRead(IR_EXIT);

  if (entrySensor == LOW && carCount < maxSlots) {
    carCount++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Car Entered");
    gate.write(90);   // open gate
    delay(2000);
    gate.write(0);    // close gate
    delay(500);
  }

  if (exitSensor == LOW && carCount > 0) {
    carCount--;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Car Exited");
    gate.write(90);
    delay(2000);
    gate.write(0);
    delay(500);
  }

  lcd.setCursor(0, 1);
  lcd.print("Slots: ");
  lcd.print(maxSlots - carCount);
  delay(500);
}
