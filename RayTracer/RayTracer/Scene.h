#pragma once
#include "Triangle.h"
#include "Tetrahedron.h"
#include <vector>
#include "Ray.h"
#include "glm/glm.hpp"
#include "Light.h";
#include "Direction.h"
#include "Sphere.h"
#include <algorithm>

struct TriangelIntersection
{
	Triangle triangle;
	Vertex point;
	float t;
};


struct SphereIntersection
{
	Sphere sphere;
	Vertex point;
	Direction Normal;
	bool find = false;
};


class Scene
{
public:
	Scene();
	void print();
	TriangelIntersection DetectTriangel(Ray &r);
	SphereIntersection DetectSphere(Ray &r);
	//Triangle Room[24];

	const std::vector<Triangle> triangles;
	const std::vector<Sphere> spheres;
	const Light light;
	void AddTetrahedra(Tetrahedron &t);
	void AddLightSource(Light &L);
	void AddSphere(const Sphere &S);
	ColorDbl GetLightContribution(Vertex &point, Direction &Normal);
	//const static int NR_SHADOW_RAYS = 20;

private:
	Vertex vertex[14];
	void initVertex();
	void initTriangle();
	

};

