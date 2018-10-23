#include "stdafx.h"
#include "Scene.h"


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


ColorDbl Scene::GetLightContribution(Vertex &point, Direction &Normal)
{
	ColorDbl clr;

	//Loop for all shadowrays
	for (int i = 0; i < 200; i++)
	{
		//Get direction towards arbitary point on light triangle
		Vertex Randomp = light.GetTringle().GetRandomPoint();
		Ray r(point, Randomp);
		
		//Get the closest intersection
		TriangelIntersection inter = DetectTriangel(r);

		//Get the length from point to light/intersection
		double LightLenght = point.dist(Randomp);
		double InterLenght = point.dist(inter.point);

		//If interseption length is larger than lightlength just skip rest
		if (abs(LightLenght - InterLenght) > 0.0001) {
			continue;
		}
		//Normalize normal "unnecessary?"
		Normal.normalize();

		//Get a direction from point to light
		Direction TowardsLight = r.End - r.Start;

		// get the geometric scalar
		double Cos_in = TowardsLight.Scalar(Normal)/ TowardsLight.Length();
		double Cos_out = (TowardsLight*-1).Scalar(light.GetTringle().normal)/ TowardsLight.Length();
		if (Cos_out < 0) {
			Cos_out = 0.0;
		}
		else if (Cos_out > 1.0) {
			Cos_out = 1.0;
		}
		double Geometric = Cos_in * Cos_out;

		if (true) {

		}
		//Add light and the geometric 
		clr += light.GetTringle().Color*Geometric/(pow(TowardsLight.x,2.0)+ pow(TowardsLight.y, 2.0)+ pow(TowardsLight.z, 2.0));
		
	}
	//Add area to light and divide by nr of shadowrays
	return clr*light.GetTringle().GetArea()/(double)200.0;
}
