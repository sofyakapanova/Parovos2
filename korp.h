#pragma once
#include "MyRectangle.h"
using namespace System::Drawing;
class korp : public MyRectаngle
{
public:
	korp(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 20;
		height = h * 10;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::DarkGray), x, y, weight, height);
		A->DrawRectangle(gcnew Pen(Color::Black), x, y, weight, height);
	}
};
