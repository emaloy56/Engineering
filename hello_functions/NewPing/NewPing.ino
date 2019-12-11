#include <NewPing.h>
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int ledPin = 6;
int counter = 0;
void setup()
{
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
}

void loop()
{
   
 /*  The first part of the code Sets up the functions for the ultrasonic sensor and how it will communicate with the LED. 
 It will also tell the LED to when the distance is 10cm. */


	delay(50);
	Serial.print("Ping: ");
	Serial.print(sonar.ping_cm());
	Serial.println("cm");
	if (sonar.ping_cm() < 10)
	
/* Second part tells the LED Length of time it binks and how fast it goes. 
It Will tell the LED what to do when the counter hits 0, 
which it will start to fade out.*/

	{
		digitalWrite(ledPin, LOW);
		delay(100);
		digitalWrite(ledPin, HIGH);
		delay(100);
		counter = 0;
	}

	/* The third part will communicate what will happen after the counter hits zero. 
	It will turn to counter 1 which will counsel out counter 0. 
	It says how bright it gets and how long the fade will last. */ 
	else if (counter == 0)
	{		
		for (int brightness = 255; brightness > 0; --brightness)
		{
			analogWrite(ledPin, brightness);
			delay(5);
		}
		counter = 1;
	}
}
