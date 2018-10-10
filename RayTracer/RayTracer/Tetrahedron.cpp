#include "stdafx.h"
#include "Tetrahedron.h"


Tetrahedron::Tetrahedron()
{
	Vertex v = Vertex(8, 3, 2, 1);
	CreateTetra(v);
}


Tetrahedron::~Tetrahedron()
{
}

void Tetrahedron::CreateTetra(Vertex _v)
{
	top = _v;
	Vert[0] = top;
	Vert[1] = Vertex((top.x - sideDist), (top.y - sideDist), (top.z - height), 1);	//Närmast
	Vert[2] = Vertex((top.x + sideDist), (top.y - sideDist), (top.z - height), 1);	//Höger
	Vert[3] = Vertex(top.x, (top.y + sideDist), (top.z - height), 1);		//Vänster

	//Create the triangles

	triangle[0] = Triangle(Vert[0], Vert[1], Vert[2], ColorDbl(1.0, 0, 0)); //Framsida
	triangle[1] = Triangle(Vert[0], Vert[2], Vert[3], ColorDbl(0.0, 1.0, 0)); //Höger baksida
	triangle[2] = Triangle(Vert[0], Vert[3], Vert[1], ColorDbl(1.0, 0, 1.0)); //Vänster baksida
	triangle[3] = Triangle(Vert[1], Vert[3], Vert[2], ColorDbl(1.0, 1.0, 0.0)); //Botten
}
