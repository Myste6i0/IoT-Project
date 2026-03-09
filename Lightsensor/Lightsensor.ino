#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("HelloMakiri");
  pinMode(A0, INPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Moist = analogRead(A0);
  float light = digitalRead(12);
  float M = (Moist / 1024) * 100;
  float Moistper = 100 - M;
  Serial.print("*");
  Serial.print(light);
  Serial.print(",");
  Serial.print(Moistper);
  Serial.print("#");

  Serial.println();

  lcd.clear();
  lcd.print("Moisture ");
  delay(500);
  lcd.clear();

  // lcd.print("content : ");
  // delay(1000);
  // lcd.clear();

  lcd.print(Moistper);
  delay(500);
  lcd.clear();

  lcd.print("Light : ");
  delay(500);
  lcd.clear();

  // lcd.print("Intensity : ");
  // delay(1000);
  // lcd.clear();

  if (light == 1) {
    lcd.print("Needed");
    delay(500);
    lcd.clear();
  } else {
    lcd.print("Not Need");
    delay(500);
    lcd.clear();
  }
  // lcd.print(light);
  // delay(1000);
  // lcd.clear();

  if (light != 1) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  if (Moistper >= 30) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }

  // delay(1000);
}