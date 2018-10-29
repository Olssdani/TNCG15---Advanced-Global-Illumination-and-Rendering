#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere() 
{
	center.x = 0;
	center.y = 0;
	center.z = 0;
	radius = 0;
	type = 0;
	color = ColorDbl(0.0, 0.0, 0.0);
}

Sphere::Sphere(const double x, const double y, const double z, const double r, const ColorDbl &c, const int t)
{
	center.x = x;
	center.y = y;
	center.z = z;
	radius = r;
	type = t;
	color = ColorDbl(c);
}

Sphere::Sphere(const Vertex &pos, double r, const ColorDbl &c, const int t)
{
	center.x = pos.x;
	center.y = pos.y;
	center.z = pos.z;
	radius = r;
	type = t;
	color = ColorDbl(0.0, 0.0, 0.0);
}

ColorDbl Sphere::GetColor()
{
	return color;
}

bool Sphere::RayIntersect(const Ray &ray, Vertex &p)
{
	//start point
	Vertex o = ray.Start;
	//Direction and then normalize it.
	Direction l = ray.End - ray.Start;
	l.normalize();

	double a = l.Scalar(l);
	double b = 2.0*l.Scalar(o - center);
	double c = (o - center).Scalar(o - center) - pow(radius, 2.0);
	double d1 = -b / 2.0;
	double d2 = -b / 2.0;
	double sq = pow(b / 2.0, 2.0) - a * c;

	if (sq > 0.0)
	{
		d1 += sqrt(sq);
		d2 -= sqrt(sq);
		Vertex P1 = Vertex(ray.Start.x + d1 * l.x, ray.Start.y + d1 * l.y, ray.Start.z + d1 * l.z, 1.0);
		Vertex P2 = Vertex(ray.Start.x + d2 * l.x, ray.Start.y + d2 * l.y, ray.Start.z + d2 * l.z, 1.0);
		if (ray.Start.dist(P1) < ray.Start.dist(P2))
		{
			p = P1;
		}
		else {
			p = P2;
		}

		return true;
	}else
	{
		return false;
	}
}

Direction Sphere::getNormal(const Vertex &p)
{
	Direction temp = Direction(p.x - center.x, p.y - center.y, p.z - center.z);
	temp.normalize();
	return temp;
}

Ray Sphere::Bounce(Ray &r, Vertex &p)
{
	Direction direction;
	Direction normal = getNormal(p);
	direction = r.dir - normal * (r.dir.Scalar(normal))*2.0;
	direction.normalize();
	return Ray(p, direction);
}