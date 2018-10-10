#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere() 
{
	center.x = 0;
	center.y = 0;
	center.z = 0;
	radius = 0;
	color = ColorDbl(0.0, 0.0, 0.0);
}

Sphere::Sphere(double x, double y, double z, double r)
{
	center.x = x;
	center.y = y;
	center.z = z;
	radius = r;
	color = ColorDbl(0.0, 0.0, 0.0);
}

Sphere::Sphere(Vertex pos, double r)
{
	center.x = pos.x;
	center.y = pos.y;
	center.z = pos.z;
	radius = r;
	color = ColorDbl(0.0, 0.0, 0.0);
}

bool Sphere::RayIntersect(Ray ray)
{
	//start point
	Vertex o = ray.Start;
	//Direction and then normalize it.
	Direction l = ray.End - ray.Start;
	l.normalize;

	double a = l.Scalar(l);
	double b = 2.0*l.Scalar(o - center);
	double c = (o - center).Scalar(o - center) - pow(radius, 2.0);
	double d1 = -b / 2.0;
	double d2 = -b / 2.0;
	double sq = pow(b / 2.0, 2.0) - a * c;

	if (sq > 0.0)
	{
		d1 += sq;
		d2 -= sq;
		return true;
	}else
	{
		return false;
	}
}