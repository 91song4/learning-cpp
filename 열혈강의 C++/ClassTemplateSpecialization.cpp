#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

template<class T>
class Point
{
private:
	T xpos, ypos;

public:
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

public:
	Point(T x=0, T y=0)
		: xpos(x)
		, ypos(y)
	{}
};

template<class T>
class SimpleDataWrapper
{
private:
	T mdata;

public:
	void ShowDataInfo(void)
	{
		cout << "Data: " << mdata << endl;
	}

public:
	SimpleDataWrapper(T data)	
		: mdata(data)
	{}
};

template<>
class SimpleDataWrapper<char*>
{
private:
	char* mdata;

public:
	void ShowDataInfo(void)
	{
		cout << "String: " << mdata << endl;
		cout << "Length: " << strlen(mdata) << endl;
	}

public:
	SimpleDataWrapper(const char* data)
		: mdata(new char[strlen(data) + 1])
	{
		strcpy_s(mdata, strlen(data) + 1, data);
	}

	~SimpleDataWrapper()
	{
		delete[] mdata;
	}
};

template<>
class SimpleDataWrapper<Point<int>>
{
private:
	Point<int> mdata;

public:
	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}

public:
	SimpleDataWrapper(int x, int y)
		: mdata(x,y)
	{}

};

int main(void)
{
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap("Class Template Specialization");
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();
	return 0;
}