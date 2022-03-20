#include<iostream>
using std::cout;
using std::endl;

class SoSimple // Polymorphic 클래스 - 하나 이상의 가상함수를 지니는 클래스
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
	void ShowSimpleInfo() // 오버라이딩 된 ShowSimpleInfo함수는 기초 클래스의 ShowSimpleInfo가 가상함수이기 때문에 이역시 가상함수이다.
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{
	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	return 0;
}