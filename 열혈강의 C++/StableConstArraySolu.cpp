#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}

public:
	int GetArrLen() const { return arrlen; }

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

	// const멤버함수 - 18행 함수와 오버로딩 관계 - 배열요소의 값을 단순반환 하는 형태.
	int& operator[]	(int idx) const	
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

// 매개변수형이 const 이므로 ref.operator[]연산자 함수는 18행이 아닌 29행 const멤버함수를 호출한다.
void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;
}

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;	// const로 선언되지 않은 arr.operator[]연산자는 18행의 함수를 호출한다.

	ShowAllData(arr);
	return 0;
}