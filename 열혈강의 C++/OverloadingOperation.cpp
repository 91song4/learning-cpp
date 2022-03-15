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

public:
	Point operator+(const Point& ref)	//operator+라는 이름의 함수
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
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
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1+pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}