#include<iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* pptr = new Point;
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p2.ypos;
	return *pptr;
}

int main(void)
{
	Point* ptr1 = new Point;
	ptr1->xpos = 2;
	ptr1->ypos = 3;
	
	Point* ptr2 = new Point;
	ptr2->xpos = 3;
	ptr2->ypos = 2;

	Point& pptr = PntAdder(*ptr1, *ptr2);

	cout << pptr.xpos << ' ' << pptr.ypos;

	delete ptr1;
	delete ptr2;
	delete &pptr;

	return 0;
}