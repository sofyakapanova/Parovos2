#pragma once
using namespace System::Drawing;

class MyRectаngle
{
protected:
	int x, y;
	int weight, height;
public:
	void MyRectangle(int _x, int _y, int _weight, int _height)
	{
		x = _x;
		y = _y;
		weight = _weight;
		height = _height;
	}
	void move(int dx)
	{
		x += dx;
	}
	virtual void draw(Graphics^ A) = 0;
};
