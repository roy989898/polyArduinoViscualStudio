/*
 Name:		polyArduinoVS.ino
 Created:	2017/3/25 下午 10:34:12
 Author:	pomingpo
*/

#include "ArduinoThread\Thread.h"
#include "ArduinoThread\\ThreadController.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif


Thread myThread;
Thread myThread2;
ThreadController controller;
void setup()
{
	// initialize LED digital pin as an output.
	//Initiate Serial communication.
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);

	myThread = Thread();
	myThread.enabled = true;
	myThread.setInterval(500);
	myThread.ThreadID = 0;
	myThread.onRun(thread1Function);

	myThread2 = Thread();
	myThread2.enabled = true;
	myThread2.setInterval(500);
	myThread2.ThreadID = 1;
	myThread2.onRun(thread2Function);

	controller = ThreadController();
	// Now, put a bunch of Threads inside it, FEED it!
	controller.add(&myThread); // Notice the & before the thread, IF it's not instantied as a pointer.
	controller.add(&myThread2);



}

void thread1Function() {
	
		Serial.println("1");
		Serial.println("1-2");
		Serial.println("1-3");
		Serial.println("1-4");
		
	

}

void thread2Function() {
	
		Serial.println("2");


}

void loop()
{
	//// turn the LED on (HIGH is the voltage level)
	//digitalWrite(LED_BUILTIN, HIGH);

	//// wait for a second
	//delay(1000);

	//// turn the LED off by making the voltage LOW
	//digitalWrite(LED_BUILTIN, LOW);

	//// wait for a second
	//delay(1000);
	//Serial.print("try");

	controller.run();
}
