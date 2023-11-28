#include "MoveToPoint.h"
//#include "RhinoMan.h"
#include <iostream>
using namespace std;

bool MoveToPoint::MoveToXY(PointXY XYPointNew)
{
	  bool Didit;
	  double Tick1Calc, Tick2Calc;
	  AnglePair CurrentAngs;
	  CurrentAngs = RoboCalc.getAngpair(XYPointNew);  
	  Tick1Calc = RoboMotion.TickAng1 - (CurrentAngs.Ang1 / .12);		//gives number of clicks passed into E motor
	  Tick2Calc = RoboMotion.TickAng2 - (CurrentAngs.Ang2 / .12);		//moving only the distance from "where I am" to "where I'm going"
	
	  //SERVO E
	  //cout << "Sent to MotoMoveServo E as the distance: " << round(Tick1Calc) << endl;
	  //cout << "E Current Clicks: " << RoboMotion.TickAng1 << endl;		//we want to display the current clicks for the servo
	  Didit = RoboMotion.MotoMoveServo('E', Tick1Calc);					//sending the servo each value
	  RoboMotion.TickAng1 -= (int)Tick1Calc;
	 // cout << "E Current Clicks: " << RoboMotion.TickAng1 << endl << endl;		//we want to display the current clicks for the servo
	  
	  //cout << "-----------------------" << endl << endl;

	  //SERVO D
	  //cout << "Sent to MotoMoveServo D as the distance: " << round(Tick2Calc) << endl;
	  //cout << "D Current Clicks: " << RoboMotion.TickAng2 << endl;
	  Didit = RoboMotion.MotoMoveServo('D', (Tick2Calc - RoboMotion.EOffset));
	  RoboMotion.TickAng2 -= (int)Tick2Calc;
	  //cout << "D Current Clicks: " << RoboMotion.TickAng2 << endl;

	  //cout << "------------------------------------------------" << endl;

	  return true;
}




