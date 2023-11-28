#include <iostream>
#include <cmath>
#include <string>
#include "RhinoMan.h"
#include <windows.h>        //Used for Sleep method
#include "RhrinoSpecific.h"
using namespace std;


//Note: This routine develops a command string using a string
//and again as a character array for demo. You may pick one.
bool RhrinoSpecific::MotoMoveServo(char c, int Distance)
{
	//Add take distance and current tick count TickAng1 and TickAng2
	//and move only the difference between TickAngs and current TickAngs
	//          1. Calc diffrence between where I am and where goint
	//             move only that difference TickAng1 and TickAng2
	//          2. Store the complete value as read to
	Distance = round(Distance);
	//cout << "Dist: " << Distance << endl;
	EOffset = Distance;
	int count     = Distance / 50;      //Get loop count by arbitrary amount
	int cntRem    = abs(Distance % 50); //Get remainder
	char Number[3];                     //Two characters plus the NULL terminator
	char direction;
	char *RobCmd  = new char[80];       //C string cmd for Rhino
	string RoboCommand = "";            //Blank build string
	bool complete = true ;              //Are we complete with the move command

	//Assign the servo motor letter and direction
	RoboCommand +=  c;        // Assign motor
	direction    = (Distance > 0) ? '+' : '-';
	RoboCommand +=  direction; // Assign directiom
	RoboCommand +=  "50";      //Default for loop
						       //strcpy(RobCmd, RoboCommand.c_str()); // Older Version
	strcpy_s(RobCmd, RoboCommand.length() + 1, RoboCommand.c_str());

	for (int cnt = 0; cnt < abs(count); cnt++)
	{ //Move by fixed number loop.
		Sleep(100);  //To be replaced by ServoWait eventually
		//cout << "Move of 50 " << RobCmd << endl;
		robo << RobCmd;
		// Insert your call to the robot controller
	}

	//Create string to handle remainder
	RoboCommand = ""; //Clear string
	RoboCommand += c; //Assign motor
	RoboCommand += direction;//Assign direction
	//itoa(cntRem, Number, 10);//Convert remainder to char string ***Convert to
	_itoa_s(cntRem,Number,3,10);

	RoboCommand += Number; //Assign remainder as characters
						   //strcpy(RobCmd, RoboCommand.c_str()); // Older Version
	strcpy_s(RobCmd, RoboCommand.length() + 1, RoboCommand.c_str());
	Sleep(100);
	robo << RobCmd;
	// Insert your call to the robot controller
	//cout << "Move Remainder " << RobCmd << endl;
	return complete;
}