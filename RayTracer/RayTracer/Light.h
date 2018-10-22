#pragma once
#include "Triangle.h"
#define _USE_MATH_DEFINES
#include <math.h>
class Light
{
public:
	Light();
	Light(double watt);
	Triangle& GetTringle();
	double GetL0();
	~Light();


private:
	Triangle triangle;
	Vertex vertex[3];
	double L0 =0.0;
};

