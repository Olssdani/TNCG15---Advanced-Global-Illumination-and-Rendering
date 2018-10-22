#include "stdafx.h"
#include "Direction.h"
#include <cmath>


Direction::Direction()
{
	x = 0;
	y = 0;
	z = 0;
}

Direction::Direction(const double &_x, const double &_y, const double &_z)
{
	x = _x;
	y = _y;
	z = _z;
}

Direction Direction::operator-(const Direction &a)const
{
	Direction ans;
	ans.x = x - a.x;
	ans.y = y - a.y;
	ans.z = z - a.z;
	return ans;
}

double Direction::Scalar(const Direction &a)const
{
	return this->x * a.x + this->y * a.y + this->z * a.z;
}

Direction Direction::Cross(const Direction &a) 
{
	double NX = this->y*a.z - this->z*a.y;
	double NY = this->z*a.x - this->x*a.z;
	double NZ = this->x*a.y - this->y*a.x;
	return Direction(NX, NY, NZ);
}

double Direction::Length() 
{
	return sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0));
}

void Direction::normalize()
{
	double dist = sqrt(x*x + y * y + z * z);
	x = x / dist;
	y = y / dist;
	z = z / dist;
}

Direction Direction::operator*(const double &a)const
{
	Direction temp;
	temp.x = x*a;
	temp.y = y*a;
	temp.z = z*a;
	return temp;
}


std::ostream& operator<<(std::ostream& os, const Direction& d)
{
	os << "n: (" << d.x << ", " << d.y << ", " << d.z << ")" << std::endl;
	return os;
}