#pragma once
#include "Triangle.h"

class Tetrahedron
{
public:
	Tetrahedron(double x, double y, double z, double length);
	~Tetrahedron();
	Triangle triangle[4];

	
	
	
	//double height = 2.0;
	//double sides = 2.45;
	//double sideDist = 1.2;
	//double sides = height / sqrt(2.0 / 3.0);
	//double sideDist = sides / 2.0;
	
private :
	Vertex top;
	Vertex Vert[4];


	void CreateTetra(Vertex &v, double length);
};

