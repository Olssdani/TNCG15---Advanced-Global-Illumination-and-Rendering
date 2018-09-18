#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"


class Ray;

class Triangle
{
public:
	Triangle();
	Triangle(Vertex _p1, Vertex _p2, Vertex _p3, ColorDbl _Color);
	~Triangle();
	void rayIntersection(Ray r);
	Direction normalCalc();

	Vertex p1;
	Vertex p2;
	Vertex p3;
	ColorDbl Color;
	Direction normal;

};



