#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void SwapByRef2(int& _ref1, int& _ref2)
{
	int swap = _ref1;
	_ref1 = _ref2;
	_ref2 = swap;
}

int main(void)
{
	int num1 = 10, num2 = 20;

	SwapByRef2(num1, num2);
	cout << num1 << endl;
	cout << num2 << endl;

	return 0;
}