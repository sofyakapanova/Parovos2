#pragma once
#include "MyRectangle.h"
using namespace System::Drawing;

class kol : public MyRectаngle
{
public:
	kol(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 4;
		height = h * 4;
	}
	void draw(Graphics^ A)
	{
		A->FillEllipse(Brushes::LightYellow, x, y, weight, height);
		A->DrawEllipse(Pens::Black, x, y, weight, height);
	}
};
