#pragma once
#include "Pixel.h"
#include <new>
#include "Scene.h"

class Camera
{
public:
	Camera();
	~Camera();
	void render(Scene &scene);
	void createImage();
	void ChangeEye();
private:
	static const int height = 800;
	static const int width = 800;
	int Eye;
	Vertex Eyes[2];
	Pixel** PixelArray = new Pixel*[height];

};

