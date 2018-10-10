#pragma once
#include <iostream>
#include "Direction.h"
class Vertex
{
public:
	Vertex();
	Vertex(double _x, double _y, double _z, double _w);
	Vertex operator=(Vertex v);
	Direction operator-(Vertex s);
	friend std::ostream& operator<<(std::ostream& os, const Vertex& v);
	double x;
	double y;
	double z;
	double w;
};

