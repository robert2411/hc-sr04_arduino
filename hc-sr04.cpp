#include "hc-sr04.h"

/*
 * These variables are not in the class becourse the Interrupt function needs to use them and it cant communicate with class members (static)
 */
unsigned long m_startTime;
unsigned long m_runTime;
bool m_run1;
bool m_running;

void Hcsr04::Init(int echoPin, int pulsPin)
{
	/* set/initolise all the variables */
	m_echoPin = echoPin;
	m_pulsPin = pulsPin;
    m_run1 = false;
	m_running = false;
	m_startTime = 0;
	m_runTime = 0;
	
	/* 
	 *	initalise the ports
	 */
	pinMode(m_pulsPin,OUTPUT);
	pinMode(13,OUTPUT);
	digitalWrite(13, LOW);
	digitalWrite(m_pulsPin, LOW);
    attachInterrupt(0, Interrupt, CHANGE);
}
void Hcsr04::SendPuls()
{
	digitalWrite(m_pulsPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(m_pulsPin, LOW);
	digitalWrite(13, HIGH);
    m_running = false;
    m_run1 = true;

}
//int Hcsr04:IsFinished();
int Hcsr04::GetTime()
{
	return m_runTime;
}
int Hcsr04::GetDistence()
{
	return (m_runTime / 29 / 2);
}
void Hcsr04::Interrupt()
{
	/*
	 *	There accure 2 interrups on the pin the first one when the measurement starts and the second one when it finishes.
	 */
    if (m_run1)
    {
        m_startTime = micros();
        m_running = true;
        m_run1 = false;
    }
    else if (m_running)
	{
		m_runTime = micros() - m_startTime;
		m_running = false;
	}
	
}
