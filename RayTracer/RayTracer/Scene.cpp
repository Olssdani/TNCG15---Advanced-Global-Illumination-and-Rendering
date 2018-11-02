#include "stdafx.h"
#include "Scene.h"
#include <algorithm>


Scene::Scene()
{
	initVertex();
	initTriangle();
}

void Scene::print()
{
	for (auto tri: triangles) 
	{
		std::cout << tri;
	}
}
void Scene::initVertex()
{
	//Uppe
	vertex[0] = Vertex(-3, 0, 5, 1);
	vertex[1] = Vertex(0, 6, 5, 1);
	vertex[2] = Vertex(10, 6, 5, 1);
	vertex[3] = Vertex(13, 0, 5, 1);
	vertex[4] = Vertex(10, -6, 5, 1);
	vertex[5] = Vertex(0, -6, 5, 1);
	vertex[6] = Vertex(5, 0, 5, 1);		//Mitten

	//Nere
	vertex[7] = Vertex(-3, 0, -5, 1);
	vertex[8] = Vertex(0, 6, -5, 1);
	vertex[9] = Vertex(10, 6, -5, 1);
	vertex[10] = Vertex(13, 0, -5, 1);
	vertex[11] = Vertex(10, -6, -5, 1);
	vertex[12] = Vertex(0, -6, -5, 1);
	vertex[13] = Vertex(5, 0, -5, 1);		//Mitten

}

void Scene::initTriangle()
{
	//Tak
	triangles.push_back(Triangle(vertex[0], vertex[1], vertex[6], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[1], vertex[2], vertex[6], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[2], vertex[3], vertex[6], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[3], vertex[4], vertex[6], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[4], vertex[5], vertex[6], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[5], vertex[0], vertex[6], ColorDbl(1.0, 1.0, 1.0)));

	//Golv
	triangles.push_back(Triangle(vertex[8], vertex[7], vertex[13], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[9], vertex[8], vertex[13], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[10], vertex[9], vertex[13], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[11], vertex[10], vertex[13], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[12], vertex[11], vertex[13], ColorDbl(1.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[7], vertex[12], vertex[13], ColorDbl(1.0, 1.0, 1.0)));

	//Höger
	triangles.push_back(Triangle(vertex[0], vertex[5], vertex[7], ColorDbl(1.0, 1.0, 0.0)));
	triangles.push_back(Triangle(vertex[5], vertex[12], vertex[7], ColorDbl(1.0, 1.0, 0.0)));
	triangles.push_back(Triangle(vertex[12], vertex[5], vertex[4], ColorDbl(1.0, 0.0, 1.0)));
	triangles.push_back(Triangle(vertex[11], vertex[12], vertex[4], ColorDbl(1.0, 0.0, 1.0)));
	triangles.push_back(Triangle(vertex[11], vertex[4], vertex[3], ColorDbl(0.0, 1.0, 1.0)));
	triangles.push_back(Triangle(vertex[10], vertex[11], vertex[3], ColorDbl(0.0, 1.0, 1.0)));

	//Vänster
	triangles.push_back(Triangle(vertex[0], vertex[7], vertex[8], ColorDbl(1.0, 0.0, 0.0)));
	triangles.push_back(Triangle(vertex[0], vertex[8], vertex[1], ColorDbl(1.0, 0.0, 0.0)));
	triangles.push_back(Triangle(vertex[1], vertex[8], vertex[9], ColorDbl(0.0, 1.0, 0.0)));
	triangles.push_back(Triangle(vertex[1], vertex[9], vertex[2], ColorDbl(0.0, 1.0, 0.0)));
	triangles.push_back(Triangle(vertex[2], vertex[9], vertex[10], ColorDbl(0.0, 0.0, 1.0)));
	triangles.push_back(Triangle(vertex[2], vertex[10], vertex[3], ColorDbl(0.0, 0.0, 1.0)));
}

void Scene::AddTetrahedra(Tetrahedron &t) 
{
	for (int i = 0; i < 4; i++) 
	{
		triangles.push_back(t.triangle[i]);
	}
}

void Scene::AddLightSource(Light &L)
{
	light = L;

	//triangles.push_back(light.GetTringle());
}

void Scene::AddSphere(const Sphere &S) 
{
	spheres.push_back(S);
}
TriangelIntersection Scene::DetectTriangel(Ray &r)
{	
	std::vector<TriangelIntersection> intersections = {};
	//Loop over all triangles in the vector
	float disttriangel = 1000000.0f;
	TriangelIntersection ClosestTringle;

	for (auto &triangle : triangles)
	{
		Vertex tempPoint;
		TriangelIntersection tempIntersect;
		//Check if the ray intersect the tringle, if true add the triangle to the returning vector		
		if (triangle.rayIntersection(r, tempPoint))
		{
			tempIntersect.triangle = triangle;
			tempIntersect.point = tempPoint;
			
			//Check for closest triangle
			float dist = r.Start.dist(tempIntersect.point);
			if (dist < disttriangel) {
				disttriangel = dist;
				ClosestTringle = tempIntersect;
			}
		}
	}
	return ClosestTringle;
}


SphereIntersection Scene::DetectSphere(Ray &r)
{
	std::vector<SphereIntersection> intersections = {};
	//Loop over all triangles in the vector
	float distSphere = 1000000.0f;
	SphereIntersection ClosestSphere;

	for (auto &sphere : spheres)
	{
		Vertex tempPoint;
		SphereIntersection tempIntersect;
		//Check if the ray intersect the tringle, if true add the triangle to the returning vector		
		if (sphere.RayIntersect(r, tempPoint))
		{
			tempIntersect.sphere = sphere;
			tempIntersect.point = tempPoint;
			tempIntersect.Normal = sphere.getNormal(tempIntersect.point);
			tempIntersect.find = true;

			//Check for closest triangle
			float dist = r.Start.dist(tempIntersect.point);
			if (dist < distSphere) {
				distSphere = dist;
				ClosestSphere = tempIntersect;
			}
		}
	}
	return ClosestSphere;
}




ColorDbl Scene::GetLightContribution(Vertex &point, Direction &Normal)
{
	ColorDbl clr;
	double sum = 0;
	//Loop for all shadowrays
	for (auto &L : light.triangle)
	{
		for (int i = 0; i < 32; i++)
		{
			//Get direction towards arbitary point on light triangle
			Vertex Randomp = L.GetRandomPoint();
			Ray r(point, Randomp);
			double SinterLength = 0;
			//Get the closest intersection
			TriangelIntersection inter = DetectTriangel(r);
			SphereIntersection Sinter = DetectSphere(r);
			double SLenght = 0;
			if (Sinter.find) {
				SLenght = point.dist(Sinter.point);
			}

			//Get the length from point to light/intersection
			double LightLenght = point.dist(Randomp);
			double InterLenght = point.dist(inter.point);

			//If interseption length is larger than lightlength just skip rest
			if (abs(LightLenght - InterLenght) > 0.0001 || (Sinter.find && SLenght > 0.001)) {
				continue;
			}
			//Normalize normal "unnecessary?"
			Normal.normalize();

			//Get a direction from point to light
			Direction TowardsLight = r.End - r.Start;
			double vectorlengthSQ = std::max(1.0, TowardsLight.Scalar(TowardsLight));
			TowardsLight.normalize();
			// get the geometric scalar

			double alpha = std::max(0.0, TowardsLight.Scalar(Normal));
			double beta = std::max(0.0, (TowardsLight*-1).Scalar(L.normal));

			//std::cout << "  alpha  " << alpha << "  beta  " << beta << "  vector  " << vectorlengthSQ << "  lightvector  " << lightvec << std::endl;
			double Geometric = alpha * beta / vectorlengthSQ;

			sum += Geometric;
		}
		clr += (light.GetEmission()*L.GetArea())*sum/32.0 ;
	}
	clr = clr / light.triangle.size();
	return clr;
}
