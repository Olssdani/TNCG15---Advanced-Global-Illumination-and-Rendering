#pragma once
#include "Ray.h"

class Pixel
{
public:
	Pixel();
	~Pixel();
	ColorDbl colorDbl;
	Ray *ray;
	void UpdateColor(double _r, double _g, double _b);
	void UpdateColor(ColorDbl _c);
	void ConnectRay(Ray *_ray);
};

