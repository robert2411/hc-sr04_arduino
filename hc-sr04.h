/**************************************************************************************\
hc-sr04.h

Author  : R.J.H.M. Stevens
Started : 27-10-2014
Version : 1.0.0
Changes :
	27-10-2014 - Added comments

TODO    : Make the echo pin variable.
		  Let it run evry 100 mS using a interrupt.
\**************************************************************************************/
#ifndef  HCSR04_H_
#define  HCSR04_H_

#include "Arduino.h"
	
/**
 *	This class allows you to work with the HC-SR04 on an arduino.
 */
class Hcsr04
{
	public:
		/**
		 *	Initialise the class and set all settings correctly
		 *	
		 *	@param echoPin The port on the arduino where the echo pin of the HC-SR04 is connected to. Watch out you have to use a interrupt pin for this and they have different numbers! (e.g. pin 2 on the nano is 0 here)
		 *	@param pulsPin The port on the arduino where the puls pin of the HC-SR04 is connected to.
		 */
		void Init(int echoPin, int pulsPin);
		/**
		 *	Send out a puls (start the measurement of the distence
		 */
		void SendPuls();
		/**
		 *	Gives the time that the measurement needed.
		 *
		 *	@return The time of the measurement
		 */
		int GetTime();
		/** Get the distence (time / 29 / 2)
		 *
		 *	@return the distence in cm
		 */
		int GetDistence();
	private:
		/**
		 *	When the interrupt occurse the code will go to this function. 
		 *	This function calculates the time that the echo pin needed to go from 0 to 1
		 */
		static void Interrupt();
		int m_echoPin;				/**< The pin number of the echo pin */
		int m_pulsPin;				/**< The pin number of the puls pin */
};
#endif 
