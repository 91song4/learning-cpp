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

#endif