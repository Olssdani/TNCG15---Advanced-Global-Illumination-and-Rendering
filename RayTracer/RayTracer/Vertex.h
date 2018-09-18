#pragma once
class Vertex
{
public:
	Vertex();
	Vertex(double _x, double _y, double _z, double _w);
	~Vertex();
	Vertex operator=(Vertex v);
	double x;
	double y;
	double z;
	double w;
};

