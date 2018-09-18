#include "stdafx.h"
#include "Ray.h"
#include "Triangle.h"


Ray::Ray(Vertex _Start, Vertex _End, ColorDbl _Color, Triangle *_triangle )
{
	Start = _Start;
	End = _End;
	Color = _Color;
	triangle = _triangle;
}

