#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SelfRef
{
private:
	int num;

public:
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;
	}

	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}

public:
	SelfRef(int n)
		: num(n)
	{
		cout << "°´Ã¼»ý¼º" << endl;
	}
};

int main(void)
{
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	return 0;
}