#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SoSimple
{
private:
	static int simObjCnt;

public:
	SoSimple()
	{
		//simObjCnt = 0;
		++simObjCnt;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt;

class SoComplex
{
private:
	static int cmxObjCnt;

public:
	SoComplex()
	{
		++cmxObjCnt;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		//cmxObjCnt = 0;
		++cmxObjCnt;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
	return 0;
}

// static 변수를 생성자에서 초기화하면 안 되는 이유
// 14행, 34행 -> 객체가 생성될 때마다 static 변수는 0으로 초기화된다.
// 왜냐하면 static 변수는 객체가 생성될 때 동시에 생성되는 변수가 아니고, 이미 메모리 공간에 할당이 이뤄진 변수이기 때문이다.
// 그래서 클래스 외부에서 초기화를 별도로 정의한다.