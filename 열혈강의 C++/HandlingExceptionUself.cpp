#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	int num1, num2;
	cout << "�� ���� ���� �Է�: ";
	cin >> num1 >> num2; // num2�� 0�� ���´ٸ� -> ������ �߻���ġ

	if (num2 == 0) // ������ �߰���ġ , if���� ����ó���� ����ó���� ���� �ڵ����� ��������� ���� if ������ ���� �ľ��ϱⰡ �����.
	{
		cout << "������ 0�� �� �� �����ϴ�." << endl; //������ ó����ġ
		cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	}
	else
	{
	cout << "�������� ��: " << num1 / num2 << endl;
	cout << "�������� ������: " << num1 % num2 << endl;
	}
	return 0;
}