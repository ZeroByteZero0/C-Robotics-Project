#ifndef PARSE_H
#define PARSE_H
//#include "MasterHeader.h"
#include "RobotMotion2023.h"
//#include "CircleC.h"
#include<fstream>
#include<string>


class Parse
{
private:
    std::ifstream GCODEin;                              //GCode input file
    char     GCODE = ' ';                               //Store Current G command
    double   CurrentX = 0.0, CurrentY = 0.0;                        //Store current position
    double   X = 0.0, Y = 0.0, I = 0.0, J = 0.0;        //Store new target position
    unsigned index;                                     //Index to individual command ln.
    std::string CommandLine;                            //Store individual command lines.
    //MoveToPoint RoboTestDemo;
    //MoveToPoint* RMPtr = &RoboTestDemo;
    RobotMotion2023 RoboTestDemo;
    RobotMotion2023* RMPtr = &RoboTestDemo;
    PointXY Centertpt, targetpt;                        //Added to allow passing to existing moveto cmd
    circle TestCirc;

public:
    Parse(std::string nameFile) 
    {  
        TestCirc.setMovetoPoint(RoboTestDemo.MoveToPtr);
        GCODEin.open(nameFile);
    }
    ~Parse() { GCODEin.close(); }
    void parseLine();
    void getGODE();
    void getX();
    void getY();
    void getI();
    void getJ();

};

#endif PARSE_H