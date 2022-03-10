#include<iostream>
using std::cout;
using std::endl;

class Temporary
{
private:
	int num;

public:
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}

public:
	Temporary(int n)
		: num(n)
	{
		cout << "create obj: " << num << endl;
	}

	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
};

int main(void)
{
	// ������ �Ұ����ϰ� �� �ӽð�ü�� ���������� �Ѿ�� �Ҹ��� �ȴ�
	Temporary (100);	// �ӽð�ü�� �����Ҽ��ִ� ������ ���� ����.
	Temporary obj(100);	// ���� obj�� ���� ���� ����.
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);	// �ӽð�ü�� �����ϴ� ������ ref�� ���� ���� ����.
	cout << "********** end of main!" << endl << endl;

	return 0;
}