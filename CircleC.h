#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "MasterHeader.h"

#include "MoveToPoint.h"
class circle
{  
private:
    MoveToPoint* RoboMovetoPoint = nullptr;////////// Reference to avoid multiple tserial.
    double Angle1 = 0.0, Angle2 = 0.0, AngleDist = 0.0, Radius = 0.0;
    double Steps = 0.0, Step = 0.0, UnitDist = 0.0;
    double getAngleDist() { return AngleDist; }        
    double PointAngle(const  PointXY& P1);       
    double getCirc(double Radius);                  
    double getAngleSteps(double UnitStep, double Radius); 
    PointXY PlotPoint = { 0.0,0.0 };
    char textch = ' ';
    double test = 0.0;
    int counter = 0;
public:
    PointXY WorkingPtMv = { 0,0 };  
    double getAngle1() { return Angle1; }              
    double getAngle2() { return Angle2; }              
    double getStep() { return Step; }                  
    double AngleBWPoints(double Ang1, double Ang2); 
    void  initArc(const  PointXY& P1, const  PointXY& P2, const double UnitDistance); 
    PointXY  getXYAngleHyp(double Angle);             
    void  DoitC(const PointXY& Pt1, const PointXY& Pt2, std::string dir, const double unitStep, const PointXY& Cpt);
   
    void setMovetoPoint(MoveToPoint* RoboMove) { RoboMovetoPoint = RoboMove; }//Set MoveToPoint
};
#endif