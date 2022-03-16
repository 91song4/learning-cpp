#include<iostream>	
#include<cstdlib>
using std::cout;
using std::endl;
using std::ostream;

class Point
{
private:
	int xpos, ypos;

public:
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator<<(ostream& os, const Point* pos);

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

ostream& operator<<(ostream& os, const Point* pos)
{
	os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
	return os;
}

class BoundCheckIntArray
{
private:
	Point** arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}

public:
	int GetArrLen() const { return arrlen; }

public:
	Point*& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	Point*& operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

public:
	BoundCheckIntArray(int len)
		: arrlen(len)
	{
		arr = new Point*[len];
	}

	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

class BoundCheck2DIntArray
{
private:
	int** arr2D;

public:
	int* operator[](int idx)
	{
		return arr2D[idx];
	}

public:
	BoundCheck2DIntArray(int x, int y)
	{
		arr2D = new int*[x];
		for (int i = 0; i < x; ++i)
		{
			arr2D[i] = new int[y];
		}
	}
	
	~BoundCheck2DIntArray()
	{
		delete[] arr2D;
	}
};

int main(void)
{
	// 문제 1.
	{
	BoundCheckIntArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];

	delete arr[0];
	delete arr[1];
	delete arr[2];
	}

	// 문제 2.
	{
		BoundCheck2DIntArray arr2d(4, 5);
		for (int n = 0; n < 4; n++)
			for (int m = 0; m < 5; m++)
			arr2d[n][m] = n + m;

		for (int n = 0; n < 4; n++)
		{
			for (int m = 0; m < 5; m++)
				cout << arr2d[n][m] << ' ';
			cout << endl;
		}
	}
	return 0;
}