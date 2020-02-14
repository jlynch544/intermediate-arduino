#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int button = 8;
int bnt;
int count = 0;
int bp = 0;
void setup()
{
	lcd.init();
	lcd.backlight();
	pinMode(10, INPUT);
	Serial.begin(9600);
}

void loop()
{
	lcd.setCursor(0, 0);
	lcd.print("Hello World");
	Serial.println(digitalRead(button));
	if ((digitalRead(button) == HIGH) && (bp == 0))
	{
		count = count + 1;
		lcd.setCursor(0, 1);
		lcd.print(count);
		bp = 1;
	}
	if (digitalRead(button) == LOW)
	{
		bp = 0;
	}
}
