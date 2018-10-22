#pragma once
#include "ColorDbl.h"
const int LAMBERTIAN = 0;

class Surface
{
public:
	
	Surface(const ColorDbl &c, const int &model);
	~Surface();

	ColorDbl Reflect()const;
	ColorDbl LambertianReflection()const;


private:
	ColorDbl color;
	double rcoef =0.8;
	ColorDbl emission = ColorDbl();
	int reflectionmodel = LAMBERTIAN;

};

