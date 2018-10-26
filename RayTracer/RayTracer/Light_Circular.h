#pragma once
#include "Ray.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
class Light_Circular
{
public:
	Light_Circular(const Vertex &_center, const double &_radius, const double _watt, Vertex _Normal);

	//Get the light area
	const ColorDbl& GetLight()const;
	//Get the light area
	const double& GetLightArea()const;

	const Vertex& GetNormal()const;
	//Finds the point the ray intercepts the circular light if any.
	bool rayIntersection(const Ray &r, Vertex &point)const;

	const Vertex RandomPointOnLight()const;

private:
	Vertex center;
	double radius;
	double L0;
	double Area;
	ColorDbl EmittingLight;
	Vertex Normal;
};

