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
	const int NrOfSubPixels = 2;
	const double PixelWidth = RealWidth /(double)width;
	const double SubPixelWidth = PixelWidth / (double)NrOfSubPixels;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			ColorDbl clr;
			// get the start position for the first suboixel
			double ystart = ((double)(-j)) * PixelWidth + 1.0 - SubPixelWidth/2.0;
			double zstart = ((double)(-i)) * PixelWidth + 1.0 - SubPixelWidth/2.0;
			
			for (int k = 0; k < NrOfSubPixels; ++k) {
				for (int m = 0; m < NrOfSubPixels; ++m) {

					//Add pixel length
					Vertex SubPixelRay = Vertex(0.0,ystart -((double)m)*SubPixelWidth ,zstart - ((double)k)*SubPixelWidth, 0.0);
					//std::cout << SubPixelRay << std::endl;
					temp = Ray(Eyes[Eye], SubPixelRay);
					
					clr += CastRay(temp, scene, 0, ColorDbl(1.0, 1.0, 1.0));
				}
			}
			clr = clr / (double)pow(NrOfSubPixels, 2);
			

			/*Vertex middle = Vertex(0.0, (double)(-j * 0.0025 + 0.99875), (double)(-i * 0.0025 + 0.99875), 0.0);
			for (int k = -1; k <= 1; k = k + 2) {
				for (int m = -1; m <= 1; m = m + 2) {

					Vertex p = Vertex(0.0, middle.y + (0.00125*m / 2.0), middle.z + (0.00125*k / 2.0), 0.0);
					//std::cout << "other" << p << std::endl;
					temp = Ray(Eyes[Eye], p);
					clr += CastRay(temp, scene,0, ColorDbl(1.0, 1.0, 1.0));
				}
			}
<<<<<<< HEAD
			clr = clr / 4.0;*/
			
			//temp = Ray(Eyes[Eye], middle);
			//clr = CastRay(temp, scene, 0, ColorDbl(1.0,1.0,1.0));

			
			PixelArray[i][j].UpdateColor(clr);
			
		}
		std::cout << (double)i/height*100.0 << "%" << std::endl;
	}
}

ColorDbl Camera::CastRay(Ray &r, Scene &scene, int depth, ColorDbl importance)
{
	Ray Rout;

	//find intersection
	TriangelIntersection  intersections = scene.DetectTriangel(r);
	SphereIntersection Sintersection = scene.DetectSphere(r);

	// Find length to each intersection
	double Slenght = Sintersection.point.dist(r.Start);
	double Tlenght = intersections.point.dist(r.Start);

	Vertex LightPoint;
	//std::cout << scene.light.LightInterception(r, LightPoint) << std::endl;
	if (scene.light.LightInterception(r, LightPoint))
	{
		double Llenght = LightPoint.dist(r.Start);
		//std::cout << Llenght << std::endl;
		if (Llenght < Slenght || !Sintersection.find || Sintersection.find && Slenght < 0.001)
		{
			if (Llenght < Tlenght || abs(Llenght - Tlenght) < 0.0001)
			{
				return scene.light.GetEmission()*importance;
			}
		}

	}


	if (Slenght > 0.001 && Slenght < Tlenght && Sintersection.find) {
		Rout = Sintersection.sphere.Bounce(r, Sintersection.point);
		return  CastRay(Rout, scene, depth, importance);

	}
	else {

		if (intersections.triangle.surface == LAMBERTIAN)
		{
			//Get directlight contribution
			ColorDbl directlight = scene.GetLightContribution(intersections.point, intersections.triangle.normal);
			/*if (directlight.b > 1.0) {
				std::cout << directlight <<std::endl;
			}*/
			//Get a random direction from hemisphere
			Rout = r.SampleLambertian(intersections.triangle.normal, intersections.point);
			//
			double hemispherePDF = 1.0 / (2.0*M_PI);
			double BRDF = intersections.triangle.BRDF();
			ColorDbl Color = intersections.triangle.Color;


			double p = std::max(std::max(Color.r*BRDF, Color.b*BRDF), Color.g*BRDF);
			ColorDbl new_importance = importance * 0.8;
			double random = (double)rand() / RAND_MAX;
			if (random > 1 - p || depth > 1) {
				return importance * Color;
			}
			depth++;
			ColorDbl indirectlight = CastRay(Rout, scene, depth, new_importance);
			return	importance * Color* (directlight + indirectlight);

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
	std::cout << max << std::endl;
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
