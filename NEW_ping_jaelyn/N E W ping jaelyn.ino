#include <NewPing.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200
int LED = 3;
int val = 0;
int fade = 5;
int dst;
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup()
{
	Serial.begin(9600);
	pinMode(TRIGGER_PIN, OUTPUT);
	pinMode(LED, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
}

void loop()
{
	Serial.println(myHCSR04.ping_cm());
	delay(50);
	val = myHCSR04.ping_cm();
	analogWrite(LED, val);
}
