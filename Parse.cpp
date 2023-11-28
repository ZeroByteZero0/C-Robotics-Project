#include "Parse.h"
#include <iostream>
#include <iomanip>
//#include "RobotMotion2023.h"
//#include "MoveToPoint.h"
//#include "RhinoMan.h"
//#include "RhrinoSpecific.h"
//#include "CircleC.h"


void Parse::parseLine()
{        
    //circle TestCirc;

    unsigned LineLength;  //Hold lengtgh of current line.
    if (!GCODEin.eof() && GCODE != '8')    //Read if not end of file
        getline(GCODEin, CommandLine);
    else
        return;
    LineLength = CommandLine.length();

    //Collect G XYIJ values in each line
    for (index = 0; index < LineLength; index++)
    {
        //cout << CommandLine[index];
        switch (CommandLine[index])
        {
        case 'G': getGODE();
            break;
        case 'X': getX();
            break;
        case 'Y': getY();
            break;
        case 'I': getI();
            break;
        case 'J': getJ();
            break;
        }
    }

    PointXY Currentpt, targetpt;
    targetpt.X = X;
    targetpt.Y = Y;
    Centertpt.X = I;
    Centertpt.Y = J;
    switch (GCODE)
    {
    case '0': //call line class and populate the Gcommand in the class
        RoboTestDemo.MotoMoveServoFout();
        std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
            << " I" << std::setw(7) << I << " J" << std::setw(7) << J << std::endl;
        RoboTestDemo.Moveto('0', targetpt, Centertpt); //G00
        RoboTestDemo.MotoMoveServoFin();
        system("pause");
        break;


    case '1': //call line class and populate the Gcommand in the class
        std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
            << " I" << std::setw(7) << I << " J" << std::setw(7) << J << std::endl;
        RoboTestDemo.Moveto('1', targetpt, Centertpt); //G01
        system("pause");
        break;

    case '2': //call circle CW  and populate the Gcommand in the class
        std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
            << " I" << std::setw(7) << I << " J" << std::setw(7) << J << std::endl;
        PointXY Test2 = RoboTestDemo.getCurrent();
        TestCirc.DoitC(RoboTestDemo.getCurrent(), targetpt, "CCW", .2, Centertpt);
        RoboTestDemo.setCurrent(targetpt);      //setting the current point to the targetpt from previous command
        system("pause");
        break;

    case '3': //call circle CCW and populate the Gcommand in the class
         std::cout << "G0" << GCODE << " X" << std::setw(7) << X << " Y" << std::setw(7) << Y
            << " I" << std::setw(7) << I << " J" << std::setw(7) << J << std::endl;
        PointXY Test1 = RoboTestDemo.getCurrent();
        TestCirc.DoitC(RoboTestDemo.getCurrent(), targetpt, "CW", .2, Centertpt);
        RoboTestDemo.setCurrent(targetpt);      //setting the current point to the targetpt from previous command
        system("pause");
        break;
    }
}


void Parse::getI()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]); 
    I = atof(Temp.c_str());
    --index;
}

void Parse::getJ()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]);
    J = atof(Temp.c_str());
    --index;
}

void Parse::getY()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]);
    Y = atof(Temp.c_str());
    --index;
}

void Parse::getX()
{
    std::string Temp = "";
    while (isdigit(CommandLine[++index]) || CommandLine[index] == '.')
        Temp.append(1, CommandLine[index]);
    X = atof(Temp.c_str());
    --index;
}

void Parse::getGODE()
{
    GCODE = CommandLine[2]; 
    index = 2;
}