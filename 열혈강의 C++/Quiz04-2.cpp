#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Point
{
private:
	int xpos, ypos;

public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point center;
	int radius;

public:
	void Init(int _xpos, int _ypos, int _radius)
	{
		center.Init(_xpos, _ypos);
		radius = _radius;
	}

	void ShowCircleInfo()
	{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle innerCircle;
	Circle outterCircle;

public:
	void Init(int _xpos, int _ypos, int _radius, int _xpos2, int _ypos2, int _radius2)
	{
		innerCircle.Init(_xpos, _ypos, _radius);
		outterCircle.Init(_xpos2, _ypos2, _radius2);
	}
	void ShowRingInfo()
	{
		cout << "Inner Circle Info..." << endl;
		innerCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outterCircle.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}