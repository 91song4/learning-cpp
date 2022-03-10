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
	SoSimple obj1(2);		// �Ϲ� ��ü ����
	const SoSimple obj2(7);	// const ��ü ����

	obj1.SimpleFunc();		// 18�� �Լ� ȣ��
	obj2.SimpleFunc();		// 23�� const �Լ� ȣ��

	YourFunc(obj1);			// 39�� �Լ� ȣ�� �Ű������� const ������ �̹Ƿ� 23�� const �Լ��� ȣ��
	YourFunc(obj2);
	return 0;
}