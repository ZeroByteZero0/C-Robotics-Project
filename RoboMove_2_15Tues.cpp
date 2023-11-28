//************************************************************************  // 
// Copyright © 2023, "Johal Informations Co."                               // 
//   All rights reserved.                                                   // 
//                                                                          // 
//  Author:                                                                 // 
//     "Manjinder Johal"                                                    // 
//                                                                          // 
//  Department:                                                             // 
//     COMSC11 Advanced C++ Department		                                // 
//                                                                          // 
//  Purpose:                                                                // 
//     This program creates a Rhino Robot Moving Program					//
//                                                                          // 
//  Effects:                                                                // 
//     The expected usage is:                                               // 
//      1.  Introduce selected C++ commands                                 // 
//      2.  Serve as a baseline for 										//
//      3.  Introduce the existance of coding standards                     // 
//                                                                          // 
// Revision History                                                         // 
// //2023 "Manjinder Johal"													// 
//     - Original Version based on:											//
//				- Class Lectures											//
//																			//
//																			//
//																			// 
//************************************************************************  //
#include <iostream>
#include "Parse.h"
//#include "MoveToPoint.h"
//#include "RobotMotion2023.h"
//#include "Line.h"
using namespace std;

int main()
{

	Parse DataIn("Test1.txt");
	//DataIn.parseLine();
	while (1) //Do not use endless loops in final product fix next
	{
		DataIn.parseLine();
		//cin.get();
	}
	/*
	double x = 0, Xpoint, Ypoint;
	bool DidIGetThere;									//Responce that fininshed the move
	//MoveToPoint RoboTest;
	RobotMotion2023 Robo;

	for (int x = 0; x < 10; x++)
	{
	cout << "Enter your X co-ordinate: ";
	cin >> Xpoint;
	cout << "Enter your Y co-ordinate: ";
	cin >> Ypoint;
	cout << endl;

	PointXY DummyPoint = { 10,10 };
	PointXY SomeTestPoint{ Xpoint,Ypoint };

	Robo.Moveto('1', SomeTestPoint, DummyPoint);
	//DidIGetThere = RoboTest.MoveToXY(SomeTestPoint);
	}
		

	system("pause");
	return 0;
	*/
}