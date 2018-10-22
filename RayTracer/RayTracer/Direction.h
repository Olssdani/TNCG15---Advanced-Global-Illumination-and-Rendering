#pragma once
#include <iostream>
class Vertex;

class Direction
{
public:
	Direction();
	Direction(const double &_x, const double &_y, const double &_z);
	Direction operator-(const Direction &a)const;
	Direction operator*(const double &a)const;
	double Scalar(const Direction &a)const;
	Direction Cross(const Direction &a);
	void normalize();
	double Length();

	friend std::ostream& operator<<(std::ostream& os, const Direction& d);

	double x;
	double y;
	double z;
};

