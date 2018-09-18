#include "stdafx.h"
#include "Direction.h"


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
