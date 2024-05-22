#pragma once
#include "MyRectangle.h"
using namespace System::Drawing;

class wind : public MyRectаngle
{
public:
	wind(int xl = 0, int yl = 0, int h = 0)
	{
		x = xl;
		y = yl;
		weight = h * 3;
		height = h * 3;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::LightBlue), x, y, weight, height);
		A->DrawRectangle(gcnew Pen(Color::DarkBlue), x, y, weight, height);
	}
};
