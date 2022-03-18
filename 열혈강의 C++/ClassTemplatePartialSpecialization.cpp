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
class MySimple<int, double>	// 전체 특수화
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
class MySimple<T1, double> // T2를 double로 부분 특수화
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
	MySimple<char, double> obj1; // 부분 특수화
	obj1.WhoAreYou();

	MySimple<int, long> obj2;
	obj2.WhoAreYou();

	MySimple<int, double> obj3;	// 전체 특수화
	obj3.WhoAreYou();
	return 0;
}

// 51행을 보면 int, double은 부분특수화에도 해당하고, 전체특수화에도 해당한다.
// 이러한 경우에는 부분특수화보다 전체특수화가 더 우선시 된다