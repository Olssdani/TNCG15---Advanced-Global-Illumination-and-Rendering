#include "stdafx.h"
#include "Ray.h"
#include "Triangle.h"

Ray::Ray()
{
	Start = Vertex();
	End = Vertex();
	Color = ColorDbl();
	triangle = nullptr;
}

Ray::Ray(Vertex _Start, Vertex _End )
{
	Start = _Start;
	End = _End;
	Color = ColorDbl();
	triangle = nullptr;
}

void Ray::GetLocalCoordSyst(Vertex &Point) 
{
	Vertex X


}
