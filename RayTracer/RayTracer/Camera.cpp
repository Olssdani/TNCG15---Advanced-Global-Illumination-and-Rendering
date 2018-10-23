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
	//std::cout << scene.NR_SHADOW_RAYS << std::endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			temp = Ray(Eyes[Eye], Vertex(0.0, (double)(-j * 0.0025 + 0.99875), (double)(-i * 0.0025 + 0.99875), 0));
			TriangelIntersection  intersections = scene.DetectTriangel(temp);

			ColorDbl directlight = scene.GetLightContribution(intersections.point, intersections.triangle.normal);


			PixelArray[i][j].UpdateColor(intersections.triangle.Color*directlight);
		}
		
		std::cout << (double)i/height*100.0 << "%" << std::endl;
	}
}

//Create and display image
void Camera::createImage()
{
	Display picture(height, width);
	//Make doubles to RGB and insert to CImg
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (max <  PixelArray[i][j].colorDbl.r)
			{
				max = PixelArray[i][j].colorDbl.r;
			}
			if (max <  PixelArray[i][j].colorDbl.g)
			{
				max = PixelArray[i][j].colorDbl.g;
			}
			if (max < PixelArray[i][j].colorDbl.b)
			{
				max = PixelArray[i][j].colorDbl.b;
			}

		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			picture(j, i, 0) = sqrt(PixelArray[i][j].colorDbl.r)*255.99 / sqrt(max);
			picture(j, i, 1) = sqrt(PixelArray[i][j].colorDbl.g)*255.99 / sqrt(max);
			picture(j, i, 2) = sqrt(PixelArray[i][j].colorDbl.b)*255.99 / sqrt(max);
		}
	}
	//Show
	picture.display_image();
	int i = 0;
	std::cin >> i;
	

}
