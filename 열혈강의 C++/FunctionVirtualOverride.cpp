#include<iostream>
using std::cout;
using std::endl;

class First
{
public:
	virtual void Myfunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
	virtual void Myfunc() { cout << "SecondFunc" << endl; }	
	// 최상위 부모클래스에서 virtual Myfunc()로 virtual키워드가 붙어서 가상함수가 된다. virtual 키워드를 안적어도 되지만 명시적으로 적어주는것이 좋다.
};

class Third : public Second
{
public:
	virtual void Myfunc() { cout << "ThirdFunc" << endl; }
	// 최상위 부모클래스에서 virtual Myfunc()로 virtual키워드가 붙어서 가상함수가 된다. virtual 키워드를 안적어도 되지만 명시적으로 적어주는것이 좋다.
};

int main(void)
{
	Third* tptr = new Third();	
	Second* sptr = tptr;		
	First* fptr = sptr;			

	fptr->Myfunc();
	sptr->Myfunc();
	tptr->Myfunc();
	delete tptr;
	return 0;
}

// 함수가 가상함수(virtual)로 선언되면, 해당 함수호출 시, 포인터의 자료형을 기반으로 호출대상을 결정하지 않고,
// 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정한다.