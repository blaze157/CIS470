#include "stdafx.h"
#include "math.h"

double square(double num)
{
	return num*num;
}

double circularDistance(double ang1, double ang2)
{
	double distance = ang1 - ang2;

	while (distance < -pi)
	{
		distance += 2*pi;
	}
	while (distance > pi)
	{
		distance -= 2*pi;
	}

	return distance;
}
