#include<iostream>
using std::cout;
using std::endl;

template <typename T>
T Add(T num1, T num2)
{
	return num1+num2;
}

int main(void)
{
	// �Լ��̸��� �ڷ����� �����Ͽ� ȣ���ϸ� ���޹޴� ���ڸ� ������ �ڷ������� ��ȯ��Ų�� �׷��� 16���� �ս��� �߻��Ѵ�.
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;

	// �Լ��̸��� �ڷ����� �������� ������ ������ �ڷ����� �����Ͽ� �ڷ����� �����Ѵ�. 16��� 22���� ���⼭ ���̰� �߻��Ѵ�.
	cout << Add(15, 20) << endl;
	cout << Add(2.9, 3.7) << endl;
	cout << Add(3.2, 3.2) << endl;
	cout << Add(3.14, 2.75) << endl;
	return 0;
}