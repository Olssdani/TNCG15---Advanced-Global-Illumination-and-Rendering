#pragma once
#include "Triangle.h"
#include "Tetrahedron.h"
#include <vector>
#include "Ray.h"
#include "glm/glm.hpp"

struct TriangelIntersection
{
	Triangle triangle;
	Vertex point;
	float t;
};


class Scene
{
public:
	Scene();
	void print();
	TriangelIntersection DetectTriangel(Ray &r);
	//Triangle Room[24];
	std::vector<Triangle> triangles;
	void AddTetrahedra(Tetrahedron &t);
	//Tetrahedron tetra[1];

private:
	Vertex vertex[14];
	void initVertex();
	void initTriangle();
};

