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

	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	Point& operator-()
	{
		xpos *= -1;
		ypos *= -1;
		return *this;
	}

	Point& operator~()
	{
		int temp = xpos;
		xpos = ypos;
		ypos = temp;
		return *this;
	}

	friend Point& operator--(Point& ref);

public:
	Point(int x = 0, int y = 0)
		: xpos(x)
		, ypos(y)
	{}
};


int main(void)
{
	// 문제 1.
	{
		Point pos1(1, 2);
		Point pos2 = -pos1;
		pos2.ShowPosition();
	}

	// 문제 2.
	{
		Point pos1(1, 2);
		Point pos2 = ~pos1;
		pos2.ShowPosition();
	}


	return 0;
}

Point& operator--(Point& ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}
