#include<iostream>
using std::cout;
using std::endl;

class Point
{
private:
	int xpos, ypos;

public:
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point& operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}

	friend Point operator*(int num, Point& ref);

public:
	Point(int x = 0, int y = 0)
		: xpos(x)
		, ypos(y)
	{}
};


int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = 3 * pos;
	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();
	return 0;
}

Point operator*(int num, Point& ref)
{
	return ref*num;
}
