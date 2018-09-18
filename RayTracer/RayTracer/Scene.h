#pragma once
#include "Triangle.h"


class Scene
{
public:
	Scene();
	~Scene();

private:
	Vertex vertex[14];
	Triangle Room[24];

	void initVertex();
	void initTriangle();

};

