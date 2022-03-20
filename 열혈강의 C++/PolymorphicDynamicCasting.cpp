#include<iostream>
using std::cout;
using std::endl;

class SoSimple // Polymorphic Ŭ���� - �ϳ� �̻��� �����Լ��� ���ϴ� Ŭ����
{
public:
	virtual void ShowSimpleInfo() // �����Լ�
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex :public SoSimple
{
public:
	void ShowSimpleInfo() // �������̵� �� ShowSimpleInfo�Լ��� ���� Ŭ������ ShowSimpleInfo�� �����Լ��̱� ������ �̿��� �����Լ��̴�.
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