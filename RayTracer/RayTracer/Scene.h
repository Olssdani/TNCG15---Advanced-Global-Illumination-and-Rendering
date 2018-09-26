#pragma once
#include "Triangle.h"


class Scene
{
public:
	Scene();
	~Scene();
	void print();
	Triangle Room[24];
private:
	Vertex vertex[14];
	

	void initVertex();
	void initTriangle();

	
};

