#pragma once
#include "Triangle.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Light
{
public:
	Light();
	ColorDbl GetEmission();
	double GetL0();
	~Light();
	bool LightInterception(Ray& r, Vertex& p);
	std::vector<Triangle> triangle;

private:
	
	Vertex vertex[3];
	double L0 =0.0;
};

