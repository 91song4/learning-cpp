#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
private:
	int xpos, ypos;

public:
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

public:
	friend ostream& operator<<(ostream& os, const Point& pos);

public:
	Point(int x = 0, int y = 0)
		: xpos(x)
		, ypos(y)
	{
		cout << "Point 按眉 积己" << endl;
	}

	~Point()
	{
		cout << "Point 按眉 家戈" << endl;
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr
{
private:
	Point* posptr;

public:
	Point& operator*() const
	{
		return *posptr;
	}
	
	Point* operator->() const
	{
		return posptr;
	}

public:
	SmartPtr(Point* ptr)
		: posptr(ptr)
	{}

	~SmartPtr()
	{
		delete posptr;
	}
};

int main(void)
{
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}