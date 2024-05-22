#pragma once
using namespace System::Drawing;
#include "parovos.h"
#include "van.h"
#include "Myline.h"

class train
{
private:
	parovos* Mai;
	van* much;
	Myline* lines;
	int count = 0;

public:
	train(int rdx = 0, int rdy = 0, int h = 0, int n = 0) {
		Mai = new parovos(rdx - 20 * h, rdy - 10 * h, h);
		much = new van[n];
		lines = new Myline[n];
		for (int i = 0; i < n; i++)
		{
			much[i] = van(rdx - (i + 2) * 20 * h - (i + 1) * h, rdy - 10 * h, h);
			lines[i] = Myline(rdx - (i + 1) * 21 * h, rdy, rdx - (i + 1) * 20 * h - (i)*h, rdy);
		}
		count = n;
	}
	train(const train* tmp)
	{
		count = tmp->count;
		Mai = tmp->Mai;
		much = new van[count];
		lines = new Myline[count];
		for (int i = 0; i < count; i++)
		{
			much[i] = tmp->much[i];
			lines[i] = tmp->lines[i];
		}
	}

	train& operator=(train tmp)
	{
		if (count != tmp.count)
		{
			if (count != 0)
			{
				delete[] much;
				delete[] lines;
			}
			count = tmp.count;
			much = new van[tmp.count];
			lines = new Myline[tmp.count];
		}
		for (int i = 0; i < count; i++)
		{
			much[i] = tmp.much[i];
			lines[i] = tmp.lines[i];
		}
		Mai = tmp.Mai;
		return *this;
	}

	void move(int dx)
	{
		Mai->move(dx);
		for (int i = 0; i < count; i++)
		{
			much[i].move(dx);
			lines[i].Move(dx, 0, dx, 0);
		}

	}

	void draw(Graphics^ g)
	{
		Mai->draw(g);
		for (int i = 0; i < count; i++)
		{
			much[i].draw(g);
			lines[i].DrawMyline(g);
		}
	}
};
