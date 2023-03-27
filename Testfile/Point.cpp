#include "Point.h"
Point::Point()
{
	x = 0;
	y = 0;
	flag = 0;
}

Point::Point(int px, int py)
{
	x = px;
	y = py;
	flag = 0;
}

void Point::Point_setX(int px)
{
	x = px;
}

void Point::Point_setY(int py)
{
	y = py;
}

bool Point::Point_setFlag(int pflag)
{
	if (pflag == -1 || pflag == 0 || pflag == 1)
	{
		flag = pflag;
		return true;
	}
	return false;
}

int Point::Point_getX()
{
	return x;
}

int Point::Point_getY()
{
	return y;
}

int Point::Point_getFlag()
{
	return flag;
}


