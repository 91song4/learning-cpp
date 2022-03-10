#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool IsPositive(int num)
{
	if (num <= 0)
		return 0;
	else
		return true;
}

int main(void)
{
	bool isPos;
	int num;
	cout << "Input number: ";
	cin >> num;

	isPos = IsPositive(num);
	if (isPos)
		cout << "Positive number" << endl;
	else
		cout << "Negative number" << endl;

	return 0;
}