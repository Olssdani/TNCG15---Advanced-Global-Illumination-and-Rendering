#include "stdafx.h"
#include "Triangle.h"
#include "Ray.h"


Triangle::Triangle()
{
	p1 = Vertex();
	p2 = Vertex();
	p3 = Vertex();
	Color = ColorDbl(0, 0, 0);
	normal = Direction(0, 0, 0);
}

Triangle::Triangle(Vertex _p1, Vertex _p2, Vertex _p3, ColorDbl _Color)
{
	p1 = _p1;
	p2 = _p2;
	p3 = _p3;
	Color = _Color;
	normal = normalCalc();
	normal.normalize();
}

Triangle::Triangle(Vertex _p1, Vertex _p2, Vertex _p3, ColorDbl _Color, int type)
{
	p1 = _p1;
	p2 = _p2;
	p3 = _p3;
	Color = _Color;
	normal = normalCalc();
	normal.normalize();
	surface = type;
}


bool Triangle::rayIntersection(Ray &r, Vertex & p)
{
	const double EPSILON = 0.000000000001;
	double a, f, u, v;
	//Möller trumbore algorithm
	Direction T = r.Start - p1;
	Direction E1 = p2 - p1;
	Direction E2 = p3 - p1;
	Direction D = r.dir;
	D.normalize();
	Direction P = Direction(D.y * E2.z - D.z*E2.y, D.z*E2.x - D.x*E2.z, D.x*E2.y - D.y*E2.x);
	a = P.Scalar(E1);
	if (abs(a) < EPSILON)
		return false;

	f = 1 / a;

	u = T.Scalar(P) * f;
	if (u < 0.0 || u > 1.0)
		return false;

	Direction Q = Direction(T.y * E1.z - T.z*E1.y, T.z*E1.x - T.x*E1.z, T.x*E1.y - T.y*E1.x);

	v = D.Scalar(Q) * f;

	if (v < 0.0 || v > 1.0 || u + v > 1)
		return false;

	double t = Q.Scalar(E2) * f;
	if (t > EPSILON)
	{
		p = GetBarycentric(u, v);
		return true;
	}
	else
	{
		return false;
	}
}

Direction Triangle::normalCalc()
{
	Direction a = Direction(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	Direction b = Direction(p3.x - p1.x, p3.y - p1.y, p3.z - p1.z);

	//cross product
	Direction c = Direction(a.y * b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	c.normalize();
	return c;
	
}

std::ostream& operator<<(std::ostream& os, const Triangle& t)
{
	os << "p1: " << t.p1 << std::endl << "p2: " << t.p2 << std::endl << "p3: " << t.p3 << std::endl << "Normal: " << t.normal << std::endl;
	return os;
}

double Triangle::GetArea()
{
	Direction AB= p2 - p1;
	Direction AC= p3 - p1;
	return AB.Cross(AC).Length();
}

Vertex Triangle::GetRandomPoint()
{
	double u = ((double)rand()) / (double)RAND_MAX;
	double v = ((double)rand()) / (double)RAND_MAX;
	//double v = 1.0 - u;
	if (u + v > 1.0) {
		return GetRandomPoint();
	}

	return GetBarycentric(u, v);

}

Vertex Triangle::GetBarycentric(double u, double v)
{
	Vertex p;
	p.x = (1 - u - v)*p1.x + u*p2.x + v*p3.x;
	p.y = (1 - u - v)*p1.y + u*p2.y + v*p3.y;
	p.z = (1 - u - v)*p1.z + u*p2.z + v*p3.z;
	return p;
}