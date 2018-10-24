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

ColorDbl ColorDbl::operator+(ColorDbl c)
{
	ColorDbl temp;
	temp.r = r+ c.r;
	temp.b = b +c.b;
	temp.g = g +c.g;
	return temp;
}

ColorDbl ColorDbl::operator/(double t)const
{
	ColorDbl temp;
	temp.r = r / t;
	temp.b = b / t;
	temp.g = g / t;
	return temp;
}

void ColorDbl::operator+=(ColorDbl c)
{

	this->r +=  c.r;
	this->b +=  c.b;
	this->g +=  c.g;
}

ColorDbl ColorDbl::operator*(ColorDbl c)const
{
	ColorDbl temp;
	temp.r = r * c.r;
	temp.b = b * c.b;
	temp.g = g * c.g;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const ColorDbl& c)
{
	os << "r: " << c.r << " g: " << c.g << " b: " << c.b;
	return os;
}