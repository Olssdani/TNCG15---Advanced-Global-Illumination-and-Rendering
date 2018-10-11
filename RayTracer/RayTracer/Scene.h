#pragma once
#include "Triangle.h"
#include "Tetrahedron.h"
#include <vector>

struct TriangelIntersection
{
	Triangle triangle;
	Vertex point;
};


class Scene
{
public:
	Scene();
	void print();
	std::vector<TriangelIntersection> DetectTriangel(Ray &r);
	//Triangle Room[24];
	std::vector<Triangle> triangles;
	void AddTetrahedra(Tetrahedron &t);
	//Tetrahedron tetra[1];

private:
	Vertex vertex[14];

	void initVertex();
	void initTriangle();


	
};

