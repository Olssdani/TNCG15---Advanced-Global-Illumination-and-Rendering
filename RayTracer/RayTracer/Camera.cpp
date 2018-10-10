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
	Eye = 0;

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
<<<<<<< HEAD
			Ray temp(Eyes[1], Vertex(0.0, (double)(-j * 0.0025 + 0.99875), (double)(-i * 0.0025 + 0.99875), 0));
=======
			//Initate the ray from eye through a pixel(i,j)
			temp = Ray(Eyes[1], Vertex(0.0, -j * 0.0025 + 0.99875, i * 0.0025 - 0.99875, 0));
>>>>>>> cc52106fa25b9bcf344bdc166306fb61d27b2a94
			for (int k = 0; k < 24; k++)
			{
				if (scene.Room[k].rayIntersection(temp))
				{
					//Update color for pixel
					PixelArray[i][j].UpdateColor(scene.Room[k].Color);
<<<<<<< HEAD
				
			}
			for (int l = 0; l < 4; l++)
			{
				//std::cout << scene.tetra[0].triangle[l] << std::endl;
				if (scene.tetra[0].triangle[l].rayIntersection(temp))
				{
					PixelArray[i][j].UpdateColor(scene.tetra[0].triangle[l].Color);
					//std::cout << "halloo" << std::endl;
				}
=======
					
					//Update the max colorvalue
					if (rmax < scene.Room[k].Color.r)
					{
						rmax = scene.Room[k].Color.r;
					}
					if (gmax < scene.Room[k].Color.g)
					{
						gmax = scene.Room[k].Color.g;
					}
					if (bmax < scene.Room[k].Color.b)
					{
						bmax = scene.Room[k].Color.b;
					}
				}		
>>>>>>> cc52106fa25b9bcf344bdc166306fb61d27b2a94
			}
		}
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
