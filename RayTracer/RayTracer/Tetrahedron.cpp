#include "stdafx.h"
#include "Tetrahedron.h"


Tetrahedron::Tetrahedron(double x, double y, double z, double length)
{
	Vertex v = Vertex(x, y, -z, 1);
	//
	CreateTetra(v, length);
}


Tetrahedron::~Tetrahedron()
{
}

void Tetrahedron::CreateTetra(Vertex &_v, double length)
{
	float w = 0.0f;
	Vert[0] = Vertex(_v.x+(1.0/3.0)*sqrt(3.0)*length, _v.y+0.0, _v.z+0.0, w );
	Vert[1] = Vertex(_v.x - (1.0 / 6.0)*sqrt(3.0)*length, _v.y + (1.0 / 2.0)*length, _v.z+0.0, w);	//Närmast
	Vert[2] = Vertex(_v.x - (1.0 / 6.0)*sqrt(3.0)*length, _v.y - (1.0 / 2.0)*length, _v.z + 0.0, w);	//Höger
	Vert[3] = Vertex(_v.x +0.0, _v.y + 0.0, _v.z +(1.0/3.0)*sqrt(6)*length, w);		//Vänster

	triangle[0] = Triangle(Vert[0], Vert[1], Vert[3], ColorDbl(1.0, 0, 0)); //Framsida
	triangle[1] = Triangle(Vert[1], Vert[2], Vert[3], ColorDbl(0.0, 1.0, 0)); //Höger baksida
	triangle[2] = Triangle(Vert[0], Vert[3], Vert[2], ColorDbl(1.0, 0, 1.0)); //Vänster baksida
	triangle[3] = Triangle(Vert[0], Vert[2], Vert[1], ColorDbl(1.0, 1.0, 0.0)); //Botten
	//top = _v;
	//Vert[0] = top;
	//Vert[1] = Vertex((top.x - sideDist), (top.y - sideDist), (top.z - height), 1);	//Närmast
	//Vert[2] = Vertex((top.x + sideDist), (top.y - sideDist), (top.z - height), 1);	//Höger
	//Vert[3] = Vertex(top.x, (top.y + sideDist), (top.z - height), 1);		//Vänster

	//Create the triangles

	//triangle[0] = Triangle(Vert[0], Vert[1], Vert[2], ColorDbl(1.0, 0, 0)); //Framsida
	//triangle[1] = Triangle(Vert[0], Vert[2], Vert[3], ColorDbl(0.0, 1.0, 0)); //Höger baksida
	//triangle[2] = Triangle(Vert[0], Vert[3], Vert[1], ColorDbl(1.0, 0, 1.0)); //Vänster baksida
	//triangle[3] = Triangle(Vert[1], Vert[3], Vert[2], ColorDbl(1.0, 1.0, 0.0)); //Botten
}
