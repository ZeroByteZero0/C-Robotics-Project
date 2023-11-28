#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <math.h>
#include "Line.h"
using namespace std;

Line::Line(float Len) { Length = Len; }


double Line::getLength(PointXY Pt1, PointXY Pt2)
{
	setLength(Pt1, Pt2);
	return Length;

}
void   Line::setLength(PointXY Pt1, PointXY Pt2) //see page 153
{
	double XLen;
	double YLen;

	if (Pt1.X < 0)
		if (Pt2.X < 0)
			XLen = Pt1.X - Pt2.X;
		else
			XLen = -Pt1.X + Pt2.X;
	else

		if (Pt2.X < 0)
			XLen = Pt1.X + -Pt2.X;
		else
			XLen = Pt1.X - Pt2.X;

	if (Pt1.Y < 0) //neg

		if (Pt2.Y < 0)
			YLen = Pt1.Y + Pt2.Y;
		else
			YLen = -Pt1.Y - Pt2.Y;
	else
		if (Pt2.Y < 0)
			YLen = Pt1.Y + -Pt2.Y;
		else
			YLen = Pt1.Y - Pt2.Y;
	Length = sqrt(pow((XLen), 2) + pow((YLen), 2));


}

PointXY Line::getNextPt(double Angle, PointXY Start, PointXY End, double Dist)
{
	PointXY ReturnXY;
	//Angle = -(Angle - (M_PI/2));
	ReturnXY.Y = (Dist * cos(Angle * (M_PI / 180))); //+ Start.Y;
	ReturnXY.X = (Dist * sin(Angle * (M_PI / 180))); //+ Start.X;
	if ((End.X <= 0 && End.Y < 0) || (End.X > 0 && End.Y < 0))
	{
		ReturnXY.Y = -ReturnXY.Y;
		ReturnXY.X = -ReturnXY.X;
	}
	return ReturnXY;
}


double Line::getAngleFromXY(PointXY Pt1, PointXY Pt2)
{
	double Rads = atan((Pt2.X - Pt1.X) / (Pt2.Y - Pt1.Y));
	return (180 / M_PI) * Rads;
}

double  Line::getLineSteps(double UnitStep)
{
	return int(Length / UnitStep);
}
