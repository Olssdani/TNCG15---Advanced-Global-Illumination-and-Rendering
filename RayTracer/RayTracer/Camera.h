#pragma once
#include "Pixel.h"
#include <new>
#include "Scene.h"
#include <algorithm>

class Camera
{
public:
	//Constructor
	Camera();
	~Camera();
	//Send rays through all pixels
	void render(Scene &scene);
	//Print image to screen.
	void createImage();
	//Change Eye
	void ChangeEye();

	ColorDbl CastRay(Ray &r, Scene &scene, int depth, ColorDbl importance);
	//ColorDbl CastRay(Ray &r, Scene &scene, int depth);
private:
	static const int height = 800;
	static const int width = 800;
	
	//Index for which eye that is used
	int Eye;
	Vertex Eyes[2];
	Pixel** PixelArray = new Pixel*[height];

	//Maximum color value
	double max = 0.0;

};

