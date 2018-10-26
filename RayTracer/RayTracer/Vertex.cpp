#include "stdafx.h"
#include "Vertex.h"
#include <cmath>



Vertex::Vertex()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vertex::Vertex(const double &_x, const double &_y, const double &_z, const double &_w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vertex::Vertex(const Vertex& v) 
{
	x = v.x;
	y =	v.y;
	z = v.z;
	w = v.w;
}

void Vertex::operator=(const Vertex &v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

double Vertex::dist(const Vertex &v)const
{
	return sqrt(pow(this->x - v.x, 2.0)+ pow(this->y - v.y, 2.0)+pow(this->z - v.z, 2.0));
}

bool Vertex::operator==(const Vertex& v)
{
	double epsilon = 0.000001;
	if (std::abs(this->x - v.x)<epsilon &&std::abs(this->y - v.y)<epsilon && std::abs(this->z - v.z)<epsilon)
	{
		return true;
	}
	else {
		return false;
	}
}

Direction Vertex::operator-(const Vertex& v)const 
{
	return Direction(this->x - v.x, this->y - v.y, this->z - v.z);
}
std::ostream& operator<<(std::ostream& os, const Vertex& v)
{
	os << "x: " << v.x << " y: " << v.y << " z: " << v.z;
	return os;
}