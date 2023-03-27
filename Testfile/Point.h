#pragma once
class Point
{
private:
	int x;
	int y;
	int flag;	// 1 if X, -1 if O, 0 if empty
public:
	Point();	//constructor

	Point(int, int);	//constructor

	void Point_setX(int);	//Set new value for x

	void Point_setY(int);	//set new value for y

	bool Point_setFlag(int);	//Set flag value for a point

	int Point_getX();	//Get x value

	int Point_getY();	//Get y value

	int Point_getFlag();	//Get value of flag
	
};

