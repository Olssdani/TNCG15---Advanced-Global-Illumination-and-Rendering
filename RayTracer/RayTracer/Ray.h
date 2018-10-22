#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "glm/glm.hpp"

class Triangle;

class Ray
{
public:
	Ray();
	Ray(Vertex _Start, Vertex _End);




	Vertex Start;
	Vertex End;
	ColorDbl Color;
	Triangle *triangle;
	glm::mat4 tranform;
	glm::mat4 invtransform;
};


