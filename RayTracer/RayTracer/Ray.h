#pragma once
#include "Vertex.h"
#include "ColorDbl.h"

class Triangle;

class Ray
{
public:
	Ray(Vertex _Start, Vertex _End, ColorDbl _Color, Triangle *_triangle);
	
	Vertex Start;
	Vertex End;
	ColorDbl Color;
	Triangle *triangle;
};


