#include "stdafx.h"
#include "Surface.h"
#define _USE_MATH_DEFINES
#include <cmath>


Surface::Surface(const ColorDbl &c , const int &model)
{
	color.r = c.r;
	color.b = c.b;
	color.g = c.g;
	reflectionmodel = model;
}

Surface::~Surface()
{
}



ColorDbl Surface::Reflect()const 
{
	if (reflectionmodel == LAMBERTIAN) {
		return LambertianReflection();
	}
}
ColorDbl Surface::LambertianReflection()const
{
	return color*(rcoef);
}