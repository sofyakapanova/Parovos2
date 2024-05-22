#pragma once
#include "MyRectangle.h"
using namespace System::Drawing;

class truba : public MyRectаngle
{
public:
	truba(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 2;
		height = h * 5;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::DarkRed), x, y, weight, height);
		A->DrawRectangle(gcnew Pen(Color::Black), x, y, weight, height);
	}
};
