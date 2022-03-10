#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SoSimple
{
private:
	int num;

public:
	SoSimple& AddNum(int n)		
	{
		num += n;
		return *this;
	}

	void SimpleFunc()
	{
		cout << "SimpleFunc: " << num << endl;
	}

	void SimpleFunc()	const
	{
		cout << "const SimpleFunc: " << num << endl;
	}

	void ShowData()	const		
	{
		cout << "num: " << num << endl;
	}

public:
	SoSimple(int n)
		: num(n)
	{}
};

void YourFunc(const SoSimple& obj)
{
	obj.SimpleFunc();
}

int main(void)
{
	SoSimple obj1(2);		// 일반 객체 생성
	const SoSimple obj2(7);	// const 객체 생성

	obj1.SimpleFunc();		// 18행 함수 호출
	obj2.SimpleFunc();		// 23행 const 함수 호출

	YourFunc(obj1);			// 39행 함수 호출 매개변수가 const 참조자 이므로 23행 const 함수를 호출
	YourFunc(obj2);
	return 0;
}