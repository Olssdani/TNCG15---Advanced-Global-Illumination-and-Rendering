#pragma once
#include <iostream>
#include "Vertex.h"

class Direction
{
public:
	Direction();
	Direction(double _x, double _y, double _z);
	Direction(Vertex p);
	~Direction();
	Direction operator-(Direction a);
	double Scalar(Direction a);

	void normalize();

	friend std::ostream& operator<<(std::ostream& os, const Direction& d);

	double x;
	double y;
	double z;
};

