#pragma once
#include "Triangle.h"
class Light
{
public:
	Light();
	~Light();


private:
	Triangle triangle;
	Vertex vertex[3];

};

