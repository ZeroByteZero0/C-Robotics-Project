#define _USE_MATH_DEFINES
#include "CircleC.h"
//#include "RhinoMan.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

void circle::DoitC(const PointXY& Pt1, const PointXY& Pt2, std::string dir, const double unitStep, const PointXY& Cpt)
{    
    //so we do not overwrite at the origin.        
    PointXY WorkPt1;           
    PointXY WorkPt2;

    WorkPt1.X = Pt1.X - Cpt.X;
    WorkPt1.Y = Pt1.Y - Cpt.Y;
    WorkPt2.X = Pt2.X - Cpt.X;
    WorkPt2.Y = Pt2.Y - Cpt.Y;
    counter = 0;

    //Pt1.X -= Cpt.X;  //Keep in mind that we are actually changing the point passed in
    //Pt1.Y -= Cpt.Y;  //We could change to pass by value. 4-14-2023. Lets use a working
    //Pt2.X -= Cpt.X;  //Copy instead to preserve the original.  Should Pt1 and 2 be const?
    //Pt2.Y -= Cpt.Y;

    initArc(WorkPt1, WorkPt2, unitStep); //Lets initArc using the working copy instead.
    double CCAngle1;                     //CCAngle1-2 used to determine distance to travel
    double CCAngle2;
    double TempAngleDist;

    
    TempAngleDist = -(circle::AngleBWPoints(getAngle1(), getAngle2()));
    if (TempAngleDist > 0)
    {
        CCAngle2 = TempAngleDist;
        CCAngle1 = TempAngleDist - 360;
    }
    else
        CCAngle2 = TempAngleDist;

    if (AngleBWPoints(getAngle1(), getAngle2()) >= 0)  //set CCAngle 
    {
        CCAngle1 = (360 - AngleBWPoints(getAngle1(), getAngle2()));
    }
    else
    {
        CCAngle1 = -(360 + AngleBWPoints(getAngle1(), getAngle2()));
    }

    //Test cout for data testing and observation
    if (dir == "CCW")  //Test Print data Block to be removed
    {
        Steps = abs(CCAngle1 / getStep());
    }
    else
    {
        Steps = abs(CCAngle1 / getStep());
    }

    
    test = getAngle2() + 360;  // Test data for break point to be removed
    if (dir == "CCW")
        
        while (Angle1 < 360 + getAngle2() && dir == "CCW")// G03
        {
            test = 360 + getAngle2();
            PlotPoint = getXYAngleHyp(Angle1);  //Get current XYpoint

            WorkingPtMv.X = PlotPoint.X + Cpt.X;
            WorkingPtMv.Y = PlotPoint.Y + Cpt.Y;
            cout << "X: " << fixed << setprecision(2) << WorkingPtMv.X
                << "  Y: " << setprecision(2) << WorkingPtMv.Y << endl;
            Sleep(100);
            RoboMovetoPoint->MoveToXY(WorkingPtMv);
            Angle1 += getStep();
        }
    else  //Then we are going CW.  Can we combine these two blocks?
    {
        test = getAngle2();
        while (Angle1 > (getAngle2()) && dir == "CW")//CC G02
        {
            test = getAngle2();
            PlotPoint = getXYAngleHyp(Angle1);  
            
            WorkingPtMv.X = PlotPoint.X + Cpt.X;
            WorkingPtMv.Y = PlotPoint.Y + Cpt.Y;
            cout << "X: " << fixed << setprecision(2) << WorkingPtMv.X
                << "  Y: " << setprecision(2) << WorkingPtMv.Y << endl;
            Sleep(100);
            RoboMovetoPoint->MoveToXY(WorkingPtMv);
            Angle1 -= getStep(); //Update to get next XYpoint
        }
    }

    WorkingPtMv.X = WorkPt2.X + Cpt.X;  //Lets use the working copy of Pt1 and 2
    WorkingPtMv.Y = WorkPt2.Y + Cpt.Y;
    cout << "X: " << fixed << setprecision(2) << WorkingPtMv.X
        << "  Y: " << setprecision(2) << WorkingPtMv.Y << endl;
    ////NOTE: !!!!!!!!!!!Create string to pass to movetoxy
    // WorkingPtMv.X = Pt2.X + Cpt.X;
    // WorkingPtMv.Y = Pt2.Y + Cpt.Y;
    //======= RoboMovetoPoint->MoveToXY(WorkingPtMv);
}


void  circle::initArc(const  PointXY& P1, const  PointXY& P2, const double UnitDistance)
{
    UnitDist = UnitDistance;                          //Unit distance of motion
    Angle1 = PointAngle(P1);                          //Determine Angle1
    Angle2 = PointAngle(P2);                       //Determine Angle2
    AngleDist = AngleBWPoints(Angle1, Angle2);         //Abs angular distance Angle1 and Angle2
    Radius = sqrt(pow(P1.X, 2.0) + pow(P1.Y, 2.0)); //Determine Radius given a point on Circle
    Step = getAngleSteps(UnitDist, Radius);   //Determine angle step to traverse arc
    Steps = AngleDist / Step;                     //Number of steps if we use for loop
}

//Return XY point from Angle and stored radius.
PointXY  circle::getXYAngleHyp(double Angle)
{                     //This application has been converted
    PointXY ReturnXY; //to degrees for discussion.
    ReturnXY.X = (Radius * cos(Angle * (M_PI / 180)));
    ReturnXY.Y = (Radius * sin(Angle * (M_PI / 180)));
    return ReturnXY;
}

//Return the Circumfrence.
double circle::getCirc(double Radius) { return 2 * M_PI * Radius; }

//Return total number of steps around the circle
double circle::getAngleSteps(double UnitStep, double Radius)
{
    double circ = getCirc(Radius);
    return 360 / (circ / UnitStep);
}

double circle::PointAngle(const PointXY& P1)
{
    double Angle;
    //Lets check for axis crossings and return the angle as stated
    if (P1.X == 0.0 && P1.Y > 0.0) return  90.0; //Check zero crossings
    else if (P1.X == 0.0 && P1.Y > 0.0) return 180.0; //to avoid invalid trig
    else if (P1.X == 0.0 && P1.Y < 0.0) return 270.0; //function entries.
    //NOTE if starting at angle 0 and ending at angle 0, zero is returned.
                                                       //Converted to degrees for demonstratoion.
    Angle = atan(P1.Y / P1.X) * (180 / M_PI);             //C trig functions give angle within Quad.
    if (P1.X < 0.0 && P1.Y >  0.0)  Angle = 180.0 + Angle; //(-,+)
    else  if (P1.X <= 0.0 && P1.Y <= 0.0)  Angle = Angle + 180.0; //(-,-)
    else  if (P1.X > 0.0 && P1.Y < 0.0)  Angle = 360.0 + Angle; //(+,-)
    return Angle;
}

//Return absolute angular distance between Ang1 and Ang2
double circle::AngleBWPoints(double Ang1, double Ang2)
{
    double AngleDist = Ang1 - Ang2;
    return AngleDist;
}