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
			ColorDbl clr;
			
			Vertex middle = Vertex(0.0, (double)(-j * 0.0025 + 0.99875), (double)(-i * 0.0025 + 0.99875), 0.0);
			//std::cout<< "Middle" << middle << std::endl;
			
			/*for (int k = -1; k <= 1; k = k + 2) {
				for (int m = -1; m <= 1; m = m + 2) {

					Vertex p = Vertex(0.0, middle.y + (0.00125*m / 2.0), middle.z + (0.00125*k / 2.0), 0.0);
					//std::cout << "other" << p << std::endl;
					temp = Ray(Eyes[Eye], p);
					clr = CastRay(temp, scene, 0);
				}
			}
			clr = clr / 4.0;*/
			
			temp = Ray(Eyes[Eye], middle);
			clr = CastRay(temp, scene, 0);
			
			
			
			/*for (int k = -1; k <= 1; k =k+2) {
				for (int m = -1; m <=1; m=m+2) {
					
					Vertex p = Vertex(0.0, middle.x+(0.00125*m/2.0), middle.y + (0.00125*k/2.0), 0.0);
					temp = Ray(Eyes[Eye], p);
					clr = CastRay(temp, scene, 0);
				}	
			}		
			clr = clr / 4.0;*/
			//std::cout << clr.r << " " << clr.b << " " << clr.g << std::endl;

			/*if (clr.r > 350 || clr.g > 350 || clr.b > 350)
			{
				std::cout << i << " " << j << std::endl;
				std::cout << clr.r << " " << clr.b << " " << clr.g << std::endl;
			}*/

			if (clr.r > 0 || clr.g > 0 || clr.b > 0)
			{
				//std::cout << clr << std::endl;

			}
			
			PixelArray[i][j].UpdateColor(clr);
			
		}
		
		std::cout << (double)i/height*100.0 << "%" << std::endl;
	}
}

ColorDbl Camera::CastRay(Ray &r, Scene &scene, int depth)
{
	//Colordbl temp
	ColorDbl clr = ColorDbl();
	Ray Rout;
	
	//find intersection
	TriangelIntersection  intersections = scene.DetectTriangel(r);
	SphereIntersection Sintersection = scene.DetectSphere(r);

	// Find length to each intersection
	
	double Slenght = Sintersection.point.dist(r.Start);
	double Tlenght = intersections.point.dist(r.Start);
	
	if (Slenght < Tlenght && Sintersection.find) {
		//std::cout << Sintersection.sphere.GetColor() << std::endl;
		ColorDbl dir = scene.GetLightContribution(Sintersection.point, Sintersection.Normal);
		//std::cout << Sintersection.sphere.GetColor()*dir << std::endl;
		return Sintersection.sphere.GetColor()*dir;
	}

	//If lightsource give full colorvalue
	if (intersections.triangle.surface == LIGHtSOURCE) {
		clr = intersections.triangle.Color;
		return clr;
	}

	if (intersections.triangle.surface == LAMBERTIAN)
	{
		//Get direct light contribution
		double cos_angle = (r.dir*-1).Scalar(intersections.triangle.normal) / (r.dir.Length()*intersections.triangle.normal.Length());
		ColorDbl directlight = scene.GetLightContribution(intersections.point, intersections.triangle.normal);
		clr = intersections.triangle.Color *directlight;
		
		
		if (depth <1)
		{
			depth++;
			Rout = r.SampleLambertian(intersections.triangle.normal, intersections.point);
		
			//double Angle = (Rout.dir).Scalar(intersections.triangle.normal) / (Rout.dir.Length()*intersections.triangle.normal.Length());
			//TriangelIntersection  tempinter = scene.DetectTriangel(Rout);
			//Ray temp = Ray(Rout.Start, tempinter.point);
			//double Cos_in = temp.dir.Scalar(intersections.triangle.normal);
			//double Cos_out = (temp.dir*-1).Scalar(tempinter.triangle.normal);
			/*if (Cos_out > 1.0) {
				Cos_out = 1.0;
			}
			else if (Cos_out < 0.0) {
				Cos_out = 0.0;
			}
			double Denominator = (pow(temp.dir.Length(), 2.0)*pow(temp.dir.x, 2.0) + pow(temp.dir.y, 2.0) + pow(temp.dir.z, 2.0));
			if (Denominator < 1.0) {
				Denominator = 1.0;
			}
			double Geometric = Cos_in * Cos_out / Denominator;
			if (Geometric > 1.0) {
				Geometric = 1.0;
			}*/


			ColorDbl indirectclr = CastRay(Rout, scene, depth);//*Geometric;

			double b = Rout.dir.Scalar(intersections.triangle.normal) / (Rout.dir.Length()*intersections.triangle.normal.Length());
			//clr = clr+ CastRay(Rout, scene, depth)*0.8/M_PI;
			clr = clr + (indirectclr)*(intersections.triangle.rcoef / M_PI )*b* 0.8;

		}

	}

	return clr;
	/*if (intersections.triangle.surface == LAMBERTIAN)
	{
		//Angle 
		double cos_angle = (r.dir*-1).Scalar(intersections.triangle.normal) / (r.dir.Length()*intersections.triangle.normal.Length());
		clr += (intersections.triangle.Color*intersections.triangle.rcoef / M_PI) *cos_angle;
	
		Rout = r.SampleLambertian(intersections.triangle.normal, intersections.point);
		ColorDbl directlight = scene.GetLightContribution(intersections.point, intersections.triangle.normal);
		clr = clr * directlight;
	}



	if (intersections.triangle.surface == SPECULAR)
	{
		intersections.triangle.normal.normalize();
		Direction Dout = r.dir - intersections.triangle.normal*(intersections.triangle.normal.Scalar(r.dir)*2.0);
		Rout = Ray(intersections.point, Dout);
	}

	

	if (depth < 0)
	{
		depth++;
		double Angle = (Rout.dir).Scalar(intersections.triangle.normal) / (Rout.dir.Length()*intersections.triangle.normal.Length());
		clr = clr + CastRay(Rout, scene, depth)*0.8*Angle;
	
	}
	
	return clr;*/
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
			/*if (PixelArray[i][j].colorDbl.r > 1000 / M_PI) 
			{
				PixelArray[i][j].colorDbl.r = 1000 / M_PI;
			}else if (PixelArray[i][j].colorDbl.b > 1000 / M_PI) 
			{
				PixelArray[i][j].colorDbl.b = 1000 / M_PI;
			}
			else if (PixelArray[i][j].colorDbl.g > 1000 / M_PI) {
					PixelArray[i][j].colorDbl.g = 1000 / M_PI;
			}*/
	
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
