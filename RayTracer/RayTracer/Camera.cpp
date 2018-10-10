#include "stdafx.h"
#include "Camera.h"
#include "Display.h"
#include "Ray.h"

Camera::Camera()
{
	Eyes[0] = Vertex(-2.0, 0.0, 0.0, 0.0);
	Eyes[1] = Vertex(-1.0, 0.0, 0.0, 0.0);
	Eye = 0;

	for (int i = 0; i < height; i++)
	{
		PixelArray[i] = new Pixel[width];
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			PixelArray[i][j] = Pixel();
			//PixelArray[i][j].UpdateColor((double)i, (double)j, (double)i);
		}

	}
}

void Camera::ChangeEye()
{
	if (Eye = 0)
	{
		Eye = 1;
	}
	else
	{
		Eye = 0;
	}
}

Camera::~Camera()
{
}

void Camera::render(Scene &scene)
{
	//Ray temp(Eyes[1],Vertex(1.0, 1.0, 1.0, 0));
	/*for (int i = 0; i < 24; i++)
	{
		if(scene.Room[i].rayIntersection(temp))
			std::cout << i << std::endl;
	}*/
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Ray temp(Eyes[1], Vertex(0.0, (double)(-j * 0.0025 + 0.99875), (double)(-i * 0.0025 + 0.99875), 0));
			for (int k = 0; k < 24; k++)
			{
				if (scene.Room[k].rayIntersection(temp))
					PixelArray[i][j].UpdateColor(scene.Room[k].Color);
				
			}
			for (int l = 0; l < 4; l++)
			{
				//std::cout << scene.tetra[0].triangle[l] << std::endl;
				if (scene.tetra[0].triangle[l].rayIntersection(temp))
				{
					PixelArray[i][j].UpdateColor(scene.tetra[0].triangle[l].Color);
					//std::cout << "halloo" << std::endl;
				}
			}
		}
	}
	

}

void Camera::createImage()
{
	double rmax = 0.0;
	double gmax = 0.0;
	double bmax = 0.0;

	Display picture(height, width);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (rmax < PixelArray[i][j].colorDbl.r)
			{
				rmax = PixelArray[i][j].colorDbl.r;
			}
			if (gmax < PixelArray[i][j].colorDbl.g)
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
			picture(j, i, 0) = PixelArray[i][j].colorDbl.r*255.99/ rmax;
			picture(j, i, 1) = PixelArray[i][j].colorDbl.g*255.99 / gmax;
			picture(j, i, 2) = PixelArray[i][j].colorDbl.b*255.99 / bmax;
		}

	}
	picture.display_image();
	int i = 0;
	std::cin >> i;
	

}
