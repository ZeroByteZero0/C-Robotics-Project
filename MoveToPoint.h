#ifndef MOVETOPOINT_H
#define MOVETOPOINT_H

#include "RhrinoSpecific.h"
#include "RhinoMan.h"

class MoveToPoint
{
  private:
     RhinoMath      RoboCalc;

  public:
     bool MoveToXY(PointXY);     
     RhrinoSpecific RoboMotion;

};

#endif