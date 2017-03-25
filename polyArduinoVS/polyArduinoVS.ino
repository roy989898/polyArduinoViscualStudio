/*
 Name:		polyArduinoVS.ino
 Created:	2017/3/25 下午 10:34:12
 Author:	pomingpo
*/

#include "ArduinoThread\Thread.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup()
{
	// initialize LED digital pin as an output.
	//Initiate Serial communication.
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	// turn the LED on (HIGH is the voltage level)
	digitalWrite(LED_BUILTIN, HIGH);

	// wait for a second
	delay(1000);

	// turn the LED off by making the voltage LOW
	digitalWrite(LED_BUILTIN, LOW);

	// wait for a second
	delay(1000);
	Serial.print("try");
}
