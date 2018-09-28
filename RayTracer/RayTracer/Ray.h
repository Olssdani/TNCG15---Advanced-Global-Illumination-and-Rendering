#pragma once
#include "Vertex.h"
#include "ColorDbl.h"

class Triangle;

class Ray
{
public:
	Ray(Vertex _Start, Vertex _End);
	
	Vertex Start;
	Vertex End;
	ColorDbl Color;
	Triangle *triangle;
};


