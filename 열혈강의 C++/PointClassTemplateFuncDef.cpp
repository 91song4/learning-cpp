#include<iostream>
using std::cout;
using std::endl;

template<class T>
class Point
{
private:
	T xpos, ypos;

public:
	void ShowPosition() const;
	
public:
	Point(T x=0, T y=0);
		
};

template<class T>
Point<T>::Point(T x, T y)
	: xpos(x)
	, ypos(y)
{}

template<class T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

int main(void)
{
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	return 0;
}