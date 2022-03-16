#include<iostream>
using std::cout;
using std::endl;

class Number
{
private:
	int num;
	
public:
	void ShowData() { cout << num << endl; }

public:
	Number* operator->()
	{
		return this;
	}

	Number& operator*()
	{
		return *this;
	}

public:
	Number(int n)
		: num(n)
	{}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	*num = 30;
	num->ShowData();
	(*num).ShowData();
	return 0;
}