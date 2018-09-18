#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
	initVertex();
	initTriangle();
}


Scene::~Scene()
{
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
	Room[0] = Triangle(vertex[0], vertex[1], vertex[6], ColorDbl(1.0, 1.0, 1.0));
	Room[1] = Triangle(vertex[1], vertex[2], vertex[6], ColorDbl(1.0, 1.0, 1.0));
	Room[2] = Triangle(vertex[2], vertex[3], vertex[6], ColorDbl(1.0, 1.0, 1.0));
	Room[3] = Triangle(vertex[3], vertex[4], vertex[6], ColorDbl(1.0, 1.0, 1.0));
	Room[4] = Triangle(vertex[4], vertex[5], vertex[6], ColorDbl(1.0, 1.0, 1.0));
	Room[5] = Triangle(vertex[5], vertex[0], vertex[6], ColorDbl(1.0, 1.0, 1.0));

	//Golv
	Room[6] = Triangle(vertex[8], vertex[7], vertex[13], ColorDbl(1.0, 1.0, 1.0));
	Room[7] = Triangle(vertex[9], vertex[8], vertex[13], ColorDbl(1.0, 1.0, 1.0));
	Room[8] = Triangle(vertex[10], vertex[9], vertex[13], ColorDbl(1.0, 1.0, 1.0));
	Room[9] = Triangle(vertex[11], vertex[10], vertex[13], ColorDbl(1.0, 1.0, 1.0));
	Room[10] = Triangle(vertex[12], vertex[11], vertex[13], ColorDbl(1.0, 1.0, 1.0));
	Room[11] = Triangle(vertex[7], vertex[12], vertex[13], ColorDbl(1.0, 1.0, 1.0));

	//Höger
	Room[12] = Triangle(vertex[0], vertex[5], vertex[7], ColorDbl(1.0, 1.0, 0.0));
	Room[13] = Triangle(vertex[5], vertex[12], vertex[7], ColorDbl(1.0, 1.0, 0.0));
	Room[14] = Triangle(vertex[12], vertex[5], vertex[4], ColorDbl(1.0, 0.0, 1.0));
	Room[15] = Triangle(vertex[11], vertex[12], vertex[4], ColorDbl(1.0, 0.0, 1.0));
	Room[16] = Triangle(vertex[11], vertex[4], vertex[3], ColorDbl(0.0, 1.0, 1.0));
	Room[17] = Triangle(vertex[10], vertex[11], vertex[3], ColorDbl(0.0, 1.0, 1.0));

	//Vänster
	Room[18] = Triangle(vertex[0], vertex[7], vertex[8], ColorDbl(1.0, 0.0, 0.0));
	Room[19] = Triangle(vertex[0], vertex[8], vertex[1], ColorDbl(1.0, 0.0, 0.0));
	Room[20] = Triangle(vertex[1], vertex[8], vertex[9], ColorDbl(0.0, 1.0, 0.0));
	Room[21] = Triangle(vertex[1], vertex[9], vertex[2], ColorDbl(0.0, 1.0, 0.0));
	Room[22] = Triangle(vertex[2], vertex[9], vertex[10], ColorDbl(0.0, 0.0, 1.0));
	Room[23] = Triangle(vertex[2], vertex[10], vertex[3], ColorDbl(0.0, 0.0, 1.0));
}
