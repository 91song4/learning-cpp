#include<iostream>
using std::cout;
using std::endl;

class SoSimple 
{
public:
	virtual void ShowSimpleInfo() // 가상함수
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex :public SoSimple
{
public:
	void ShowSimpleInfo() 
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{
	SoSimple* simPtr = new SoSimple; 
	SoComplex* comPtr = nullptr;
	comPtr = static_cast<SoComplex*>(simPtr); // static_cast
	comPtr->ShowSimpleInfo();
	comPtr = dynamic_cast<SoComplex*>(simPtr); // dynamic_cast
	if (comPtr == NULL)
		cout << "형 변환 실패" << endl;
	else
		comPtr->ShowSimpleInfo();
	return 0;

	// 유도클래스의 포인터 및 참조형으로 변환을 시도할 때 사용할 수 있는 두 연산자의 차이
	// 25행이 실제 가리키는객체가 유도클래스가 아닌 기초클래스이면
	// static_cast 는 제 값이 반환되지만 문제가 있을 가능성이 있다.
	// dynamic_cast 는 기초클래스가 polymorphic 클래스인경우 가능하다
	// dynamic_cast 는 그 값이 NULL로 반환된다.
}