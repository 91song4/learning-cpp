#include<iostream>
using std::cout;
using std::endl;

class AAA
{
private:
	int num;

public:
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}

public:
	AAA(int n = 0)
		: num(n)
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref)
		: num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << endl;
	}
};

class BBB
{
private:
	AAA mem;

public:
	BBB(const AAA& ref)
		: mem(ref)	// ��������ڷ� ��ü ���� -> 1�ܰ�
	{}
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref)
	{
		mem = ref;	// ��ü ������ ���Կ����� �Լ� ȣ�� -> 2�ܰ�
	}
};

int main(void)
{
	AAA obj1(12);
	cout << "****************************" << endl;
	BBB obj2(obj1);
	cout << "****************************" << endl;
	CCC obj3(obj1);
	return 0;
}