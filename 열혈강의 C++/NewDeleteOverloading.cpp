#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
private:
	int xpos, ypos;

public:
	void* operator new(size_t size)
	{
		cout << "operator new: " << size << endl;
		void* adr = new char[size];	// new 자료형()<->자료형[] 의 차이점.
		return adr;
	}

	void operator delete(void* adr)
	{
		cout << "operator delete ()" << endl;
		delete[] adr;
	}

	friend ostream& operator<<(ostream& os, const Point& pos);

public:
	Point(int x=0, int y=0)
		: xpos(x)
		, ypos(y)
	{}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);
	cout << *ptr;
	delete ptr;
	return 0;
}