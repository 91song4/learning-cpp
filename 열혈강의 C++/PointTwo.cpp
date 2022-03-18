#include"pointTwo.h"
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

Point::Point(int x, int y)
	: xpos(x)
	, ypos(y)
{}