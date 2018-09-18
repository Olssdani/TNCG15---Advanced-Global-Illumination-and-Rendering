#pragma once
#include <iostream>
class Direction
{
public:
	Direction();
	Direction(double _x, double _y, double _z);
	~Direction();

	void normalize();

	friend std::ostream& operator<<(std::ostream& os, const Direction& d);

	double x;
	double y;
	double z;
};

