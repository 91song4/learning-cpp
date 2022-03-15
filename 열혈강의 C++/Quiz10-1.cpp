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
	Point& operator+=(const Point& ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	
	Point operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	friend bool operator==(const Point& ref1, const Point& ref2)
	{
		if(ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos)
			return true;
		return false;
	}

	friend bool operator!=(const Point& ref1, const Point& ref2)
	{
		return !operator==(ref1, ref2);
	}


	friend Point operator+(const Point& pos1, const Point& pos2);	//operator+라는 이름의 함수
	friend Point operator-(const Point& pos1, const Point& pos2);

public:
	Point(int x = 0, int y = 0)
		: xpos(x)
		, ypos(y)
	{}
};

Point operator+(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

int main(void)
{
	// 문제 1.
	{
		Point pos1(3, 4);
		Point pos2(10, 20);
		Point pos3 = pos2 - pos1;

		pos1.ShowPosition();
		pos2.ShowPosition();
		pos3.ShowPosition();
	}

	// 문제 2.
	{
		Point pos1(3, 4);
		pos1.ShowPosition();
		Point pos2(10, 20);
		(pos1 += pos2).ShowPosition();
		(pos1 -= pos2).ShowPosition();
	}

	// 문제 3.
	{
		Point pos1(3, 4);
		Point pos2(10, 20);
		Point pos3(3, 4);
		pos1 == pos2;
		pos1 != pos2;
		pos1 == pos3;
		pos1 != pos3;
	}

	
	return 0;
}