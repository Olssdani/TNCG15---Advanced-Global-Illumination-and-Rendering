#include "stdafx.h"
#include "Display.h"
#include <iostream>


Display::Display(int sizeX, int sizeY)
{
	x = sizeX;
	y = sizeY;
	image = cimg_library::CImg<unsigned char>(sizeX, sizeY, 1, 3, 0);
}

int Display::GetPixelValue(int Posx, int Posy, int Channel)
{
	return image(Posx, Posy, Channel);
}

unsigned char& Display::operator()(int Posx, int Posy, int Channel)
{
	return image(Posx, Posy, Channel);
}


void Display::display_image()
{
	cimg_library::CImgDisplay main_disp(image, "Click a point");
	std::cout << "Press any q to quit" << std::endl;
	char end;
	std::cin >> end;
}