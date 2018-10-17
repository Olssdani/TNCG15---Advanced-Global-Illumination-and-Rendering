// RayTracer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CImg.h"
#include "Display.h"
#include "Scene.h"
#include <string>
#include "Camera.h"
#include <chrono>



int main()
{
	//variables
	std::string answer;
	auto start = std::chrono::system_clock::now();

	//Start text
	std::cout << "Welcome to Eriks and Daniels Monto Carlo raytracer renderer" << std::endl << std::endl;

	//Intial and start scene
	std::cout << "---------Intial room and object----------" << std::endl;
	Scene scene;
	Tetrahedron tetra(8.0,-3.0,0.0,2.0);
	scene.AddTetrahedra(tetra);
	std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
	std::cout << "Room is initialized... Took " << diff.count() << std::endl;
	std::cout << std::endl << std::endl;




	//Camera
	start = std::chrono::system_clock::now();
	Camera camera = Camera();
	diff = std::chrono::system_clock::now() - start;
	std::cout << "Camera is initialized... Took " << diff.count()  << std::endl;
	std::cout << std::endl << std::endl;




	//Rendering
	std::cout << "Rendering started..." << std::endl;
	start = std::chrono::system_clock::now();
	std::cout << std::endl << std::endl;
	camera.render(scene);
	diff = std::chrono::system_clock::now() - start;
	std::cout << "Rendering is done... Took " << diff.count() << std::endl;




	//Display 
	std::cout << "Showing picture.." << std::endl;
	std::cout << std::endl << std::endl;
	camera.createImage();
	



	//Stops from ending console 
	int i = 0;
	std::cin >> i;

	//End program
    return 0;
}

