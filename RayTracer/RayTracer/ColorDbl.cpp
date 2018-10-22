#include "stdafx.h"
#include "ColorDbl.h"


ColorDbl::ColorDbl()
{
	r = 0;
	g = 0;
	b = 0;
}

ColorDbl::ColorDbl(double _r, double _g, double _b)
{
	r = _r;
	g = _g;
	b = _b;
}

ColorDbl ColorDbl::operator*(double t)const 
{
	ColorDbl temp;
	temp.r = r * t;
	temp.b = b * t;
	temp.g = g * t;
	return temp;
}
