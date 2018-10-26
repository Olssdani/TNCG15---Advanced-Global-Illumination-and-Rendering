#include "stdafx.h"
#include "Ray.h"
#include "Triangle.h"

Ray::Ray()
{
	Start = Vertex();
	End = Vertex();
	Color = ColorDbl();
	triangle = nullptr;
	dir = End - Start;
}

Ray::Ray(Vertex _Start, Vertex _End )
{
	Start = _Start;
	End = _End;
	Color = ColorDbl();
	triangle = nullptr;
	dir = End - Start;
}

Ray::Ray(Vertex _Start, Direction _dir)
{
	Start = _Start;
	End = Vertex();
	Color = ColorDbl();
	triangle = nullptr;
	dir = _dir;
}

Ray Ray::SampleLambertian(Direction &normal, Vertex &p)
{
	/*Direction Z = normal;
	Direction Iorto = dir - Z*(dir.Scalar(Z));
	Direction X = Iorto/Iorto.Length;
	Direction Y = (X*-1).Cross(Z);
	

	glm::mat4 rot;
	RotationsMatrix(rot, X, Y, Z);


	glm::mat4 trans;
	TranslateMatrix(trans, p.x, p.y, p.z);
	
	//Create
	glm::mat4 M = rot * trans;
	glm::mat4 InverseM = glm::inverse(M);


	glm::vec4 in = glm::vec4(dir.x, dir.y, dir.z, 1.0);

	glm::vec4 temp = M *in;*/

	//Direction output = normal;
	
	double inclanation = ((double)rand()/RAND_MAX)* (M_PI/2);
	double azzimut = ((double)rand() / RAND_MAX)* (2*M_PI);;
	glm::dvec3 _in = glm::vec3(dir.x, dir.y, dir.z);
	glm::dvec3 _normal = glm::normalize(glm::vec3(normal.x, normal.y, normal.z));
	glm::dvec3 _tangent = glm::normalize((glm::cross(_in, _normal)));
	glm::dvec3 _out = _normal;


	
	_out = glm::normalize(glm::rotate(_out, inclanation, _tangent));
	_out = glm::normalize(glm::rotate(_out, azzimut, _normal));


	Direction output = Direction(_out.x, _out.y, _out.z);

	return Ray(p, output);



}

void Ray::TranslateMatrix(glm::mat4 &m, double x, double y, double z) 
{
	m[0][0] = 1.0;
	m[1][1] = 1.0;
	m[2][2] = 1.0;
	m[3][3] = 1.0;
	m[0][3] = -x;
	m[1][3] = -y;
	m[2][3] = -z;
}

void RotationsMatrix(glm::mat4 &m, Direction X, Direction Y, Direction Z)
{
	m[0][0] = X.x;
	m[0][1] = X.y;
	m[0][2] = X.z;
	m[1][0] = Y.x;
	m[1][1] = Y.y;
	m[1][2] = Y.z;
	m[2][0] = Z.x;
	m[2][1] = Z.y;
	m[2][2] = Z.z;
	m[3][3] = 1.0;
}