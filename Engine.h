#pragma once
#include <math.h>
#include "Myline.h"
using namespace System::Drawing;

class Engine
{
	Myline left;
	Myline middle;
	Myline right;
	int xm, ym, hm, xmm, ymm;
public:
	Engine(int x_m, int y_m, int h)
	{
		left = Myline(x_m, y_m, x_m, y_m - h);
		middle = Myline(x_m, y_m - h, x_m + 10 * h, y_m - h);
		right = Myline(x_m + 10 * h, y_m, x_m + 10 * h, y_m - h);
		xm = x_m; ym = y_m; hm = h;
		xmm = x_m; //center x
		ymm = y_m; //center y
	}

	void Move(int d_x)
	{
		double l = hm;
		double R = hm * 2;
		double sina = d_x / R; //математика
		double cosa = sqrt(1 - sina * sina);
		double c = 2 * l * l - 2 * cosa * l * l; // если мы наоборот, будем знать чему равно расстояние от начальной до конечной точки, то наоборот выражаем угол и находим координаты конечной точки
		double dx_m = d_x;// * cosa;
		double dy_m = d_x;// * sina;
		if (ym - hm >= ymm && xm > xmm)
			dx_m = -dx_m;
		else if (ym - hm > ymm && xm <= xmm) {
			dy_m = -dy_m;
			dx_m = -dx_m;
		}

		else if (ym - hm <= ymm && xm < xmm) {
			dy_m = -dy_m;
		}
		xm += d_x + dx_m;
		ym += dy_m;
		xmm += d_x;
		std::cout << xm << " " << ym - hm << " " << xmm << " " << ymm << std::endl;
		left.Move(d_x, 0, d_x + dx_m, dy_m);
		middle.Move(d_x + dx_m, dy_m, d_x + dx_m, dy_m);
		right.Move(d_x, 0, d_x + dx_m, dy_m);

	}
	void draw(Graphics^ g)
	{
		left.DrawMyline(g);
		middle.DrawMyline(g);
		right.DrawMyline(g);
	}
};
