#pragma once
#include "Triangle.h"
#include "Tetrahedron.h"
#include <vector>
#include "Ray.h"
#include "glm/glm.hpp"
#include "Light.h";
#include "Light_Circular.h";
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

	std::vector<Triangle> triangles;
	std::vector<Sphere> spheres;
	//Light light;
	Light_Circular light;
	void AddTetrahedra(Tetrahedron &t);
	//void AddLightSource(Light &L);
	void AddLightSource(Light_Circular &L);

	void AddSphere(const Sphere &S);
	ColorDbl GetLightContribution(Vertex &point, Direction &Normal);
	//const static int NR_SHADOW_RAYS = 20;

private:
	Vertex vertex[14];
	void initVertex();
	void initTriangle();
	

};

