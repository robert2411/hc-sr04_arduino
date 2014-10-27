#ifndef  HCSR04_H_
#define  HCSR04_H_

#include "Arduino.h"

#define  HCSR04_MAX_DISTENCE 400
#define  HCSR04_MAX_FREQUENTIE 10 // in hz

class Hcsr04
{
	public:
		int Init(int echoPin, int pulsPin);
		int SendPuls();
		int IsFinished();
		int GetTime();
		int GetDistence();
	private:
		static void Interrupt();
		int m_echoPin;
		int m_pulsPin;
};
#endif 
