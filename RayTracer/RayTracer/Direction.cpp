#include "stdafx.h"
#include "Direction.h"
#include <cmath>


Direction::Direction()
{
	x = 0;
	y = 0;
	z = 0;
}

Direction::Direction(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}


Direction::~Direction()
{
}

void Direction::normalize()
{
	double dist = sqrt(x*x + y * y + z * z);
	x = x / dist;
	y = y / dist;
	z = z / dist;
}

std::ostream& operator<<(std::ostream& os, const Direction& d)
{
	os << "n: (" << d.x << ", " << d.y << ", " << d.z << ")" << std::endl;
	return os;
}