#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class TwoNumber
{
private:
	int num1;
	int num2;

public:
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << num2 << endl;
	}

public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}

	/*TwoNumber(int num1, int num2)
		: num1(num1)
		, num2(num2)
	{}*/
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 1;
}