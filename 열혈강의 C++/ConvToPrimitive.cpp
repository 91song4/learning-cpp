#include<iostream>
using std::cout;
using std::endl;

class Number
{
private: // variable
	int num;

public: // function
	void ShowNumber() { cout << num << endl; }

public: // operator
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}

	operator int()	// int, return, 멤버변수의 자료형.. 어떠한 관계인지 정확히 알고싶다.
	{
		return num;
	}

public: // constructor, destructor
	Number(int n = 0)
		: num(n)
	{
		cout << "Number(int n = 0)" << endl;
	}

};

int main(void)
{
	Number num;
	num = 30;
	Number num2 = num + 20;
	num2.ShowNumber();
	return 0;
}