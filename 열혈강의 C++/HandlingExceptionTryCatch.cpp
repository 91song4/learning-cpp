#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	int num1, num2;
	cout << "�� ���� ���� �Է�: ";
	cin >> num1 >> num2;

	try
	{
		if (0 == num2)
			throw num2;
		cout << "�������� ��: " << num1 / num2 << endl;
		cout << "�������� ������: " << num1 % num2 << endl;
	}
	catch(int expn)
	{
		cout << "������ " << expn << "�� �� �� �����ϴ�." << endl;
		cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	}
	cout << "end of main" << endl;
	return 0;
}