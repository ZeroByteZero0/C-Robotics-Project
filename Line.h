#ifndef LINE_H
#define LINE_H

#include "MasterHeader.h"

class Line 
{
private:
	double Length;

public:
	Line(float Length = 1);
	double  getLineSteps(double UnitStep);				// Get Number of steps
	double  getAngleFromXY(PointXY Pt1, PointXY Pt2);	// Get angle from XY					
	PointXY getNextPt(double Angle, PointXY Start, PointXY End, double Distance);
	double  getLength(PointXY Pt1, PointXY Pt2);		// Return current length
	void    setLength(PointXY Pt1, PointXY Pt2);		// Set length of line
};

#endif
