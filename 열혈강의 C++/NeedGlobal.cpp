#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		++simObjCnt;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		++cmxObjCnt;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		++cmxObjCnt;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
	return 0;
}

// 전역변수를 활용한 카운트. 전역변수에 어디서든 접근이 가능하므로 데이터가 바뀔위험이 많다.