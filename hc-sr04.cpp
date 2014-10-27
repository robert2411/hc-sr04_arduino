#include "hc-sr04.h"

unsigned long m_startTime;
unsigned long m_runTime;
bool m_run1;
bool m_running;

int Hcsr04::Init(int echoPin, int pulsPin)
{
	m_echoPin = echoPin;
	m_pulsPin = pulsPin;
    m_run1 = false;
	m_running = false;
	m_startTime = 0;
	m_runTime = 0;
	
	pinMode(m_pulsPin,OUTPUT);
	pinMode(13,OUTPUT);
	digitalWrite(13, LOW);
	digitalWrite(m_pulsPin, LOW);
    attachInterrupt(0, Interrupt, CHANGE);
}
int Hcsr04::SendPuls()
{
	digitalWrite(m_pulsPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(m_pulsPin, LOW);
	digitalWrite(13, HIGH);
    m_running = false;
    m_run1 = true;
	return 0;

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
