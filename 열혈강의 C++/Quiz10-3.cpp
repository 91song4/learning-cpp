#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Point
{
private:
	int xpos, ypos;

public:
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);

public:
	Point(int x = 0, int y = 0)
		: xpos(x)
		, ypos(y)
	{}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

istream& operator>>(istream& is, Point& pos)
{
	int x, y;
	cin >> x; cin >> y;
	pos.xpos = x;
	pos.ypos = y;
	return is;
}

int main(void)
{
	Point pos1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos1;
	cout << pos1;

	Point pos2(101, 303);
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos2;
	cout << pos2;
	return 0;
}