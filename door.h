#pragma once
#include "MyRectangle.h"
using namespace System::Drawing;

class door : public MyRectаngle
{
public:
	door(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 4;
		height = h * 7;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::Gray), x, y, weight, height);
		A->DrawRectangle(gcnew Pen(Color::Black), x, y, weight, height);
	}
};
