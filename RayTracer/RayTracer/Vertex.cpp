#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vertex::Vertex(double _x, double _y, double _z, double _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vertex Vertex::operator=(Vertex v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vertex& v)
{
	os << "x: " << v.x << " y: " << v.y << " z: " << v.z;
	return os;
}