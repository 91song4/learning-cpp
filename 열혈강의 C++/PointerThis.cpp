#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

class SoSimple
{
private:
	int num;

public:
	void ShowSimpleData()
	{
		cout << num << endl;
	}

	SoSimple* GetThisPointer()
	{
		return this;
	}

public:
	SoSimple(int n)
		: num(n)
	{
		cout << "num=" << num << ", ";
		cout << "address=" << this << endl;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();	// sim1 按眉狼 林家 蔼 历厘
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();	// sim2 按眉狼 林家 蔼 历厘
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}