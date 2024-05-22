#pragma once
#include "korp.h"
#include "wind.h"
#include "door.h"
#include "kol.h"
using namespace System::Drawing;


class van
{
private:
	korp* c;
	door* d;
	wind* ws;
	kol* leftk;
	kol* rightk;
public:
	van(int x = 0, int y = 0, int h = 0)
	{
		c = new korp(x, y, h);
		d = new door(x, y + h * 3, h);
		ws = new wind[3];
		for (int i = 0; i < 3; i++)
		{
			ws[i] = wind(x + (4 + 2 * (i + 1) + 3 * i) * h, y + 2 * h, h);
		}
		leftk = new kol(x + 3 * h, y + 10 * h, h);
		rightk = new kol(x + 13 * h, y + 10 * h, h);
	}
	void draw(Graphics^ g) {
		c->draw(g);
		d->draw(g);
		for (int i = 0; i < 3; i++)
		{
			ws[i].draw(g);
		}
		leftk->draw(g);
		rightk->draw(g);
	}

	void move(int dx)
	{
		c->move(dx);
		d->move(dx);
		for (int i = 0; i < 3; i++)
		{
			ws[i].move(dx);
		}
		leftk->move(dx);
		rightk->move(dx);
	}
};
