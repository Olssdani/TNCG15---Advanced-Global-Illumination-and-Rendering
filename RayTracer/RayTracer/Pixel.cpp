#include "stdafx.h"
#include "Pixel.h"


Pixel::Pixel()
{
	colorDbl = ColorDbl(0, 0, 0);
}



Pixel::~Pixel()
{
}

void Pixel::UpdateColor(double _r, double _g, double _b)
{
	colorDbl.r = _r;
	colorDbl.g = _g;
	colorDbl.b = _b;

}

void Pixel::UpdateColor(ColorDbl _c)
{
	colorDbl.r = _c.r;
	colorDbl.g = _c.g;
	colorDbl.b = _c.b;

}

void Pixel::ConnectRay(Ray *_ray) 
{
	ray = _ray;
}
