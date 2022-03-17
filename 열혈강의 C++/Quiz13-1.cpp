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
	Point(int x=0, int y=0)
		: xpos(x)
		, ypos(y)
	{}
};

template <class T>
void SwapData(T& v1, T& v2)
{
	T temp = v1;
	v1 = v2;
	v2= temp;
	cout << "swap" << endl;
}

template <class T>
T SumArray(T arr[], const int len)
{
	T sum = 0;
	for (int i = 0; i < len; ++i)
		sum += arr[i];
	return sum;
}

int main(void)
{
	// 문제 1.
	{
		int x = 3;
		int y = 5;
		cout << "x: " << x << ", " << "y: " << y << endl;
		SwapData(x, y);
		cout << "x: " << x << ", " << "y: " << y << endl;
		
		Point ptr1(3,5);
		Point ptr2(5,3);
		ptr1.ShowPosition();
		ptr2.ShowPosition();
		
		SwapData(ptr1, ptr2);
		ptr1.ShowPosition();
		ptr2.ShowPosition();
	}

	// 문제 2.
	{
		int iArr[3] = { 1,2,3 };
		cout << SumArray(iArr, 3) << endl;
		double dbArr[3] = { 3.2, 4.2, 1.4 };
		cout << SumArray(dbArr, 3);
	}
	return 0;
}