#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 1);

void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("HelloMakiri");
}

void loop()
{
	// Do nothing here...
  int num = 23;
  lcd.clear();
  lcd.print("Moisture ");
  delay(1000);
  lcd.clear();

  lcd.print("content : ");
  delay(1000);
  lcd.clear();

  lcd.print(num);
  delay(1000);
  lcd.clear();

  lcd.print("Light");
  delay(1000);
  lcd.clear();

  lcd.print("Intensity : ");
  delay(1000);
  lcd.clear();

  lcd.print();
  delay(1000);
  lcd.clear();

}
