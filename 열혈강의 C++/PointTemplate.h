#ifndef __PointTemplate_h__
#define __PointTemplate_h__

template<class T>
class Point
{
private:
	T xpos, ypos;

public:
	void ShowPosition() const;

public:
	Point(T x = 0, T y = 0);

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

#endif