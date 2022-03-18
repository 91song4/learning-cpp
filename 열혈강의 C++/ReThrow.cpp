#include<iostream>
using std::cout;
using std::endl;

void Divide(int n1, int n2)
{
	try
	{
		if (n2 == 0)
			throw 0;
		cout << "몫: " << n1 / n2 << endl;
		cout << "나머지: " << n1 % n2 << endl;
	}
	catch (int expn)
	{
		cout << "first catch" << endl;
		throw;	// 예외를 다시 throw
	}
}

int main(void)
{
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn)
	{
		cout << "second catch" << endl;
	}
	return 0;
}