#pragma once
#include "Ray.h"
#include "Direction.h"
class Sphere
{
public:
	Sphere();
	Sphere(const double x, const double y, const double z, const double r, const ColorDbl &c, const int t);
	Sphere(const Vertex &pos, double r, const ColorDbl &c, const int t);
	bool RayIntersect(const Ray &ray, Vertex &p);
	Direction getNormal(const Vertex &p);
	ColorDbl GetColor();

private:
	Vertex center;
	double radius = 0.0;
	ColorDbl color;
	int type = 0;

};