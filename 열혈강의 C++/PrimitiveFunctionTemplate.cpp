#include<iostream>
using std::cout;
using std::endl;

template <class T1, class T2> // �� �̻��� ���ø� Ÿ���� ����� �� �ִ�.
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl; // �� ��ȯ�� ���ؼ� ���
}

int main(void)
{
	// �Լ����ø��� �Ű��������� double�� ����Ǿ��� ������ ���޵Ǵ� ���ڸ� ���ؼ� T1, T2�� �ڷ����� �������� ���Ѵ�
	// �׷��Ƿ� ���ø��Լ��� ȣ�������� ��������� ���־���Ѵ� 
	// ex) ShowData<(T1, T2)>()
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}