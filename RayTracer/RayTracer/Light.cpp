#include "stdafx.h"
#include "Light.h"


Light::Light()
{
	vertex[0] = Vertex(4, 1, 5, 1);
	vertex[1] = Vertex(6, 1, 5, 1);
	vertex[2] = Vertex(4, -1, 5, 1);
	vertex[3] = Vertex(6, -1, 5, 1);

	triangle.push_back( Triangle(vertex[0], vertex[1], vertex[2], ColorDbl(1.0, 1.0, 1.0)) );
	triangle.push_back( Triangle(vertex[1], vertex[3], vertex[2], ColorDbl(1.0, 1.0, 1.0)) );

	L0 = 1000 / M_PI;
	
}



Light::~Light()
{
}

ColorDbl Light::GetEmission()
{
	return ColorDbl(1.0, 1.0, 1.0)*L0;
}

double Light::GetL0()
{
	return L0;
}

bool Light::LightInterception(Ray& r, Vertex& p)
{
	for (auto &t : triangle)
	{
		Vertex tempPoint;
		//Check if the ray intersect the tringle, if true add the triangle to the returning vector		
		if (t.rayIntersection(r, tempPoint))
		{
			//std::cout << tempPoint.x << "  x  " << tempPoint.y << "  y  " << tempPoint.z << "  z   " << std::endl;
			p = tempPoint;
			return true;
		}
	}
	return false;
}