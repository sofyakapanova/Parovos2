#pragma once
using namespace System::Drawing;
#include "truba.h"
#include "van.h"
#include "Engine.h"
class parovos
{
	van* vagon;
	truba* tr;
	Engine* dvijok;
public:
	parovos(int xL, int yL, int h)
	{
		vagon = new van(xL, yL, h);
		tr = new truba(xL + 16 * h, yL - 5 * h, h);
		dvijok = new Engine(xL + 5 * h, yL + 12 * h, h);
	}
	parovos(const parovos* tmp)
	{
		vagon = tmp->vagon;
		tr = tmp->tr;
		dvijok = tmp->dvijok;
	}
	parovos& operator= (parovos tmp)
	{
		delete vagon;
		delete dvijok;
		vagon = tmp.vagon;
		tr = tmp.tr;
		dvijok = tmp.dvijok;
	}

	void draw(Graphics^ g) {
		vagon->draw(g);
		tr->draw(g);
		dvijok->draw(g);
	}

	void move(int dx) {
		vagon->move(dx);
		tr->move(dx);
		dvijok->Move(dx);
	}

	~parovos()
	{
		delete vagon;
		delete dvijok;
	}
};
