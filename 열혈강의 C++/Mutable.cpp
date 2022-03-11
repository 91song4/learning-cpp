#include<iostream>
using std::cout;
using std::endl;

class SoSimple
{
private:
	int num1;
	mutable int num2;	// const 함수에 대해 예외를 둔다.

public:
	void ShowSimpleData()	const
	{
		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2()	const
	{
		num2 = num1;
	}

public:
	SoSimple(int n1, int n2)
		: num1(n1)
		, num2(n2)
	{}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	return 0;
}

// mutable 키워드는 const 함수 내에서의 값의 변경을 예외적으로 허용한다