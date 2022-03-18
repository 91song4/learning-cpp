#include<iostream>
using std::cout;
using std::endl;

template<class T1, class T2>
class MySimple
{
public:
	void WhoAreYou()
	{
		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of T2: " << sizeof(T2) << endl;
		cout << "<class T1, class T2>" << endl;
	}
};

template<>
class MySimple<int, double>	// ��ü Ư��ȭ
{
public:
	void WhoAreYou()
	{
		cout << "size of T1: " << sizeof(int) << endl;
		cout << "size of T2: " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};


template<class T1>
class MySimple<T1, double> // T2�� double�� �κ� Ư��ȭ
{
public:
	void WhoAreYou()
	{
		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of T2: " << sizeof(double) << endl;
		cout << "<class T1, double>" << endl;
	}
};


int main(void)
{
	MySimple<char, double> obj1; // �κ� Ư��ȭ
	obj1.WhoAreYou();

	MySimple<int, long> obj2;
	obj2.WhoAreYou();

	MySimple<int, double> obj3;	// ��ü Ư��ȭ
	obj3.WhoAreYou();
	return 0;
}

// 51���� ���� int, double�� �κ�Ư��ȭ���� �ش��ϰ�, ��üƯ��ȭ���� �ش��Ѵ�.
// �̷��� ��쿡�� �κ�Ư��ȭ���� ��üƯ��ȭ�� �� �켱�� �ȴ�