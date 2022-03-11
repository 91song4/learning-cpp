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
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
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
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		//cmxObjCnt = 0;
		++cmxObjCnt;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
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

// static ������ �����ڿ��� �ʱ�ȭ�ϸ� �� �Ǵ� ����
// 14��, 34�� -> ��ü�� ������ ������ static ������ 0���� �ʱ�ȭ�ȴ�.
// �ֳ��ϸ� static ������ ��ü�� ������ �� ���ÿ� �����Ǵ� ������ �ƴϰ�, �̹� �޸� ������ �Ҵ��� �̷��� �����̱� �����̴�.
// �׷��� Ŭ���� �ܺο��� �ʱ�ȭ�� ������ �����Ѵ�.