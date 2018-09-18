#pragma once
#include <iostream>
class Vertex
{
public:
	Vertex();
	Vertex(double _x, double _y, double _z, double _w);
	Vertex operator=(Vertex v);
	friend std::ostream& operator<<(std::ostream& os, const Vertex& v);
	double x;
	double y;
	double z;
	double w;
};

