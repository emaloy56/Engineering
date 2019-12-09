// Hello.ino
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display.
// If 0x27 doesn't work, try 0x3F.

int buttonPin = 13;
int buttonState = 0;
int previousbuttonState = 0;
int switchPin = 0;
int counter = 0;

void setup()
{
	pinMode(buttonPin, INPUT);
	pinMode(switchPin, INPUT);
	lcd.init();
	lcd.backlight();
	lcd.print("Button presses:34");
	Serial.begin(16, 2);
}

void loop()
{
	buttonState = digitalRead(buttonPin);
	
	if (buttonState == HIGH && previousbuttonState == LOW)
	{
		counter++;
		
	}
	previousbuttonState = buttonState;


	lcd.setCursor(0, 1);
    lcd.print(counter);
    lcd.print(" ");

	Serial.print(counter);
    delay(5);
}

