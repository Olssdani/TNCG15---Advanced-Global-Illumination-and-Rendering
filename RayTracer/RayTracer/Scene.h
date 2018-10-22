#pragma once
#include "Triangle.h"
#include "Tetrahedron.h"
#include <vector>
#include "Ray.h"
#include "glm/glm.hpp"
#include "Light.h";
#include "Direction.h"

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
	Light light;
	void AddTetrahedra(Tetrahedron &t);
	void AddLightSource(Light &L);
	ColorDbl GetLightContribution(Vertex &point, Direction &Normal);
	const static int NR_SHADOW_RAYS = 200;
private:
	Vertex vertex[14];
	void initVertex();
	void initTriangle();
	

};

