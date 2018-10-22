#include "stdafx.h"
#include "Camera.h"
#include "Display.h"
#include "Ray.h"

//Constructor
Camera::Camera()
{
	//Hardcoded Eye postion
	Eyes[0] = Vertex(-2.0, 0.0, 0.0, 0.0);
	Eyes[1] = Vertex(-1.0, 0.0, 0.0, 0.0);
	Eye = 1;

	//Intiate the array
	for (int i = 0; i < height; i++)
	{
		PixelArray[i] = new Pixel[width];
		// fill Arr[i] with values
		for (int j = 0; j < width; j++)
		{
			PixelArray[i][j] = Pixel();
		}
	}
}

//Change the current eye
void Camera::ChangeEye()
{
	if (Eye = 0)
		Eye = 1;
	else
		Eye = 0;
}

//Destructor
Camera::~Camera()
{
	for (int i = 0; i < height; ++i) {
		delete[] PixelArray[i];
	}
	delete[] PixelArray;
}

//Rendering function
void Camera::render(Scene &scene)
{
	//Variables
	Ray temp;
	//Loop over all pixels
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			temp = Ray(Eyes[Eye], Vertex(0.0, (double)(-j * 0.0025 + 0.99875), (double)(-i * 0.0025 + 0.99875), 0));
			TriangelIntersection  intersections = scene.DetectTriangel(temp);




			PixelArray[i][j].UpdateColor(intersections.triangle.Color);
		}
	}
}

//Create and display image
void Camera::createImage()
{
	Display picture(height, width);
	std::cout << "Pixels";
	//Make doubles to RGB and insert to CImg
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (rmax <  PixelArray[i][j].colorDbl.r)
			{
				rmax = PixelArray[i][j].colorDbl.r;
			}
			if (gmax <  PixelArray[i][j].colorDbl.g)
			{
				gmax = PixelArray[i][j].colorDbl.g;
			}
			if (bmax < PixelArray[i][j].colorDbl.b)
			{
				bmax = PixelArray[i][j].colorDbl.b;
			}

		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			picture(j, i, 0) = PixelArray[i][j].colorDbl.r*255.99 / rmax;
			picture(j, i, 1) = PixelArray[i][j].colorDbl.g*255.99 / gmax;
			picture(j, i, 2) = PixelArray[i][j].colorDbl.b*255.99 / bmax;
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			picture(j, i, 0) = PixelArray[i][j].colorDbl.r*255.99/ rmax;
			picture(j, i, 1) = PixelArray[i][j].colorDbl.g*255.99 / gmax;
			picture(j, i, 2) = PixelArray[i][j].colorDbl.b*255.99 / bmax;
		}
	}
	//Show
	picture.display_image();
	int i = 0;
	std::cin >> i;
	

}
