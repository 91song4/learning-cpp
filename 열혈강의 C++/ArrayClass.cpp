#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;

public:
	int& operator[]	(int idx)
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
		arr = new int[len];
	}

	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;
	return 0;
}