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
	num.ShowNumber();
	return 0;
}