#include "stdafx.h"
#include "Light_Circular.h"


Light_Circular::Light_Circular(const Vertex &_center, const double &_radius, const double _watt, Vertex _Normal)
{
	center = _center;
	radius = _radius;
	L0 = _watt / M_PI;
	EmittingLight = ColorDbl(L0, L0, L0);
	Area = pow(radius, 2.0)*M_PI;
	Normal = _Normal;
}


const ColorDbl& Light_Circular::GetLight()const
{
	return EmittingLight;
}


const double& Light_Circular::GetLightArea()const
{
	return Area;
}

const Vertex& Light_Circular::GetNormal()const
{
	return Normal;
}

const Vertex Light_Circular::RandomPointOnLight()const
{
	//Set a random seed depending on time
	srand(time(NULL));
	//Get radius radius and angle
	double r = ((double)rand() / (double)RAND_MAX)*radius;
	double angle = ((double)rand() / (double)RAND_MAX)*2*M_PI;
	//Add or subsract to center depending on angle and radius
	return Vertex(center.x+cos(angle)*r, center.y+sin(angle)*r, center.z, 1.0);
}



bool Light_Circular::rayIntersection(const Ray &r, Vertex &point)const
{
	//See where which number t need to be so the ray get the same value as the circle z value
	//Light.z = Ray.start.z + t*Ray.direction.z
	if (r.dir.z < 0.0001) {
		return false;
	}
	double t = (center.z - r.Start.z) / r.dir.z;
	// Se if the point is less than 2.0 length from center
	double x = r.Start.x + t * r.dir.x;
	double y = r.Start.y + t * r.dir.y;

	//if(pow(radius,2.0)>)
	return false;





}