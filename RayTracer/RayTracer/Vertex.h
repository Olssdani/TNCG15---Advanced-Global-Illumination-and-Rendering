#pragma once
#include <iostream>
#include "Direction.h"
#include <cmath>
class Vertex
{
public:
	Vertex();
	Vertex(const double &_x, const double &_y, const double &_z, const double &_w);
	Vertex(const Vertex& v);
	double dist(const Vertex &v)const;
	void operator=(const Vertex &v);
	Direction operator-(const Vertex& v)const;
	bool operator==(const Vertex& v);
	friend std::ostream& operator<<(std::ostream& os, const Vertex& v);
	double x;
	double y;
	double z;
	double w;
};

