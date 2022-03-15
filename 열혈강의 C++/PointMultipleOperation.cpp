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

	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = pos * 3 * 2;
	cpy.ShowPosition();
	return 0;
}
