#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void Divide(int n1, int n2)
{
	if (n2 == 0)
		throw n2;
	cout << "나눗셈의 몫: " << n1 / n2 << endl;
	cout << "나눗셈의 나머지: " << n1 % n2 << endl;
}

int main(void)
{
	int n1, n2;
	cout << "두 개의 숫자 입력: ";
	cin >> n1 >> n2;

	try
	{
		Divide(n1, n2);
		cout << "나눗셈을 마쳤습니다." << endl;
	}
	catch (int expn)
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	return 0;
}