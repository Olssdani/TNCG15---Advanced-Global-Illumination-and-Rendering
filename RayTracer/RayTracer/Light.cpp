#include "stdafx.h"
#include "Light.h"


Light::Light()
{
	vertex[0] = Vertex(-3, 0, 5, 1);
	vertex[1] = Vertex(0, 6, 5, 1);
	vertex[2] = Vertex(5, 0, 5, 1);
	triangle =Triangle(vertex[0], vertex[1], vertex[2], ColorDbl(1.0, 1.0, 1.0));

}


Light::~Light()
{
}
