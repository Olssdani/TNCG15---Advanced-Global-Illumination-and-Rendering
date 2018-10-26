#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/rotate_vector.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>  


class Triangle;

class Ray
{
public:
	Ray();
	Ray(Vertex _Start, Vertex _End);
	Ray(Vertex _Start, Direction _dir);

	Ray SampleLambertian(Direction &normal, Vertex &p);

	Vertex Start;
	Vertex End;
	Direction dir;
	ColorDbl Color;
	Triangle *triangle;

private:
	void TranslateMatrix(glm::mat4 &m, double x, double y, double z);

};


