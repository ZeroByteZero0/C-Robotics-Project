#ifndef RHRINOSPECIFIC_H
#define RHRINOSPECIFIC_H

#include "tserial.h"

class RhrinoSpecific
{
	Tserial robo;
	//Tserial -- TBD to communicate with arm
	//bool SwitchStat -- TBD used for home
	//bool ServoWait -- TBD
public:
	double TickAng1 = 750.0;   //Represent the number of clicks to get from 0deg to 90deg
	double TickAng2 = 750.0;   //Represent the number of clicks to get from 0deg to 90deg
	//Todo -convert angle pair to ticks dividing by .12 pass to 
	double EOffset;
public:
	RhrinoSpecific(){
		char Ports[] = "COM4";
		robo.connect(Ports, 9600, spEVEN);
	}
	bool MotoMoveServo(char c, int Distance); //  Distance in clicks or servo divisions
	//This method will store the complete distance for servo E, the shoulder and Servo D,
	//the elbo in TickAng1 and TickAng2.  We will only move the difference between the stored
	//value in TickAng1 and 2, but store the complete number once we are done
};
#endif