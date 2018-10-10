#pragma once
#include "Triangle.h"
#include "Tetrahedron.h"

class Scene
{
public:
	Scene();
	~Scene();
	void print();
	Triangle Room[24];
	Tetrahedron tetra[1];

private:
	Vertex vertex[14];

	void initVertex();
	void initTriangle();
	void initTetra();

	
};

