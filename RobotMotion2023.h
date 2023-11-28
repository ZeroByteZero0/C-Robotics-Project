#ifndef ROBOTMOTION2023_H
#define ROBOTMOTION2023_H

#include "MasterHeader.h"  //Common point and angle types
#include "Line.h"          //Developed week 3
#include "CircleC.h"      //Will start development Next week
#include "MoveToPoint.h"   //Used in last weeks main demo
#include "RhrinoSpecific.h"
#include "CircleC.h"

class RobotMotion2023
{
private:
    //We need to set an XY reference point as we did with the 750,750
    PointXY CurrPos = { 9.0,9.0 }; //Home or overall start position
    PointXY CentPos = { 0.0,0.0 }; //Default center point for Arcs and Circles TBD
    Line LineTest;               //Instance of line object
    circle TestCirc;             //We will develop the circle class next week
    MoveToPoint     Rhino;         //Was in our main last week
    //RhrinoSpecific *RhinoSpec;


public:   //       0123            Target           Center for arcs+
    PointXY getCurrent() { return CurrPos; };
    void setCurrent(PointXY Current) { CurrPos = Current; };
    void Moveto(char Cmd, PointXY TargPos, PointXY CentPos);
    bool MotoMoveServoFout();
    bool MotoMoveServoFin();
    MoveToPoint* MoveToPtr = &Rhino;

};
#endif