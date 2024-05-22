#pragma once
using namespace System::Drawing;

class Myline
{
private:
	int x_beg, y_beg, x_end, y_end;
public:
	Myline(int x_b = 0, int y_b = 0, int x_e = 0, int y_e = 0)
	{
		x_beg = x_b;
		y_beg = y_b;
		x_end = x_e;
		y_end = y_e;
	}
	void DrawMyline(Graphics^ g)
	{
		g->DrawLine(gcnew Pen(Color::DarkRed), x_beg, y_beg, x_end, y_end);
	}
	void Move(int dxb = 0, int dyb = 0, int dxe = 0, int dye = 0)
	{
		x_beg += dxb;
		y_beg += dyb;
		x_end += dxe;
		y_end += dye;
	}
};
