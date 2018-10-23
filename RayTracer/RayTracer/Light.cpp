#include "stdafx.h"
#include "Light.h"


Light::Light()
{
	vertex[0] = Vertex(-3, 0, 5, 1);
	vertex[1] = Vertex(0, 6, 5, 1);
	vertex[2] = Vertex(5, 0, 5, 1);

	triangle = Triangle(vertex[0], vertex[1], vertex[2], ColorDbl(0., 0.0, 0.0));
	
}

Light::Light(double watt)
{
	vertex[0] = Vertex(-3, 0, 5, 1);
	vertex[1] = Vertex(0, 6, 5, 1);
	vertex[2] = Vertex(5, 0, 5, 1);
	L0 = watt/ M_PI;
	triangle =Triangle(vertex[0], vertex[1], vertex[2], ColorDbl(L0, L0, L0), LIGHtSOURCE);
	
}


Light::~Light()
{
}

Triangle& Light::GetTringle()
{
	return triangle;
}

double Light::GetL0()
{
	return L0;
}