#ifndef __PointTwo_h__
#define __PointTwo_h__

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
private:
	int xpos, ypos;

public:
	friend ostream& operator<<(ostream& os, const Point& pos);
public:
	Point(int x = 0, int y = 0);
};

#endif