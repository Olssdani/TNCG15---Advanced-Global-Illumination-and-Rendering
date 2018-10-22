#pragma once

class ColorDbl
{
public:
	ColorDbl();
	ColorDbl(double _r, double _g, double _b);

	ColorDbl operator*(double t)const;
	//ColorDbl operator*(ColorDbl c, double t);
		
	double r;
	double g;
	double b;
};

