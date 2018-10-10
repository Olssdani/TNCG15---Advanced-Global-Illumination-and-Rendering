#pragma once
#include "Ray.h"
#include "Direction.h"
class Sphere
{
public:
	Sphere();
	Sphere(double x, double y, double z, double r);
	Sphere(Vertex pos, double r);
	bool RayIntersect(Ray ray);


private:
	Vertex center;
	double radius = 0.0;
	ColorDbl color;

};