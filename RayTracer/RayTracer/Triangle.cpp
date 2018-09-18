#include "stdafx.h"
#include "Triangle.h"
#include "Ray.h"


Triangle::Triangle()
{
	p1 = Vertex();
	p2 = Vertex();
	p3 = Vertex();
}

Triangle::Triangle(Vertex _p1, Vertex _p2, Vertex _p3, ColorDbl _Color)
{
	p1 = _p1;
	p2 = _p2;
	p3 = _p3;
	Color = _Color;
	normal = normalCalc();
}


Triangle::~Triangle()
{
}

void Triangle::rayIntersection(Ray r)
{

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