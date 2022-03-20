#include<iostream>
using std::cout;
using std::endl;

class SoSimple 
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
		cout << "�� ��ȯ ����" << endl;
	else
		comPtr->ShowSimpleInfo();
	return 0;

	// ����Ŭ������ ������ �� ���������� ��ȯ�� �õ��� �� ����� �� �ִ� �� �������� ����
	// 25���� ���� ����Ű�°�ü�� ����Ŭ������ �ƴ� ����Ŭ�����̸�
	// static_cast �� �� ���� ��ȯ������ ������ ���� ���ɼ��� �ִ�.
	// dynamic_cast �� ����Ŭ������ polymorphic Ŭ�����ΰ�� �����ϴ�
	// dynamic_cast �� �� ���� NULL�� ��ȯ�ȴ�.
}