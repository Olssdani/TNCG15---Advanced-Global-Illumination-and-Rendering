#pragma once
#include "CImg.h"

class Display
{
public:
	//intiate a display object with a size
	Display(int sizeX, int sizeY);

	//Get pixel value att point x, y on a certain rgb channel
	int GetPixelValue(int Posx, int Posy, int Channel);

	//Change pixel value
	unsigned char& operator()(int Posx, int Posy, int Channel);

	//Show image
	void display_image();

private:
	//Size of picture
	int x;
	int y;
	//Image
	cimg_library::CImg<unsigned char> image;
};

