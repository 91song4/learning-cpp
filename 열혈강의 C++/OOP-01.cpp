#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// ��� 1. ���°���
// ��� 2. �Ա�
// ��� 3. ���
// ��� 4. ��ü�� �ܾ���ȸ

// ���¹�ȣ
int id = 99;
char name[100];
int deposit;
int withdraw;
int money;

void Deposit();

class userinfo
{

};
int menu()
{
	int _choose = 0;
	cout << "------Menu-----\n" << "1. ���°���\n" << "2. �� ��\n" << "3. �� ��\n" << "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" << "����: ";
	cin >> _choose;
	return _choose;
}

int check(int _choose)
{
	while (1 > _choose || 5 < _choose)
	{
		cout << "�޴��� �߸� ���� �Ǿ����ϴ�." << endl;
		_choose = menu();
	}
	return _choose;
}

void AccountOpening(int _choose)
{
	
	cout << "[���°���]" << endl << "�� ��: ";
	cin>>name;
	++id;
	Deposit();
}

void Deposit()
{
	if (99 == id)
	{
		cout << "���°����� ���ּ���" << endl;
		return;
	}
	cout << "[��  ��]" << endl << "����ID: " << id << endl << "�Աݾ�: ";
	cin >> deposit;
	cout << "�ԱݿϷ�" << endl;
	money += deposit;
}

void Withdraw()
{
	cout << "[��  ��]" << endl << "����ID: " << id << endl << "�� ��: " << money << endl << "��ݾ�: ";
	cin >> withdraw;
	if (money < withdraw)
		cout << "�ܾ��� �����մϴ�." << endl;
	money -= withdraw;
}

void AccountInformation()
{
	cout << "����ID: " << id << endl << "�� ��: " << name << endl << "�ܾ�: " << money << endl;
}


int main(void)
{
	int choose = 0;
	while (5 != choose)
	{
		choose = menu();
		choose =  check(choose);
		switch (choose)
		{
		//1. ���°���
		case 1:
			AccountOpening(choose);
			continue;
		//2. �� ��
		case 2:
			Deposit();
			continue;
		//3. �� ��
		case 3:
			Withdraw();
			continue;
		//4. �������� ��ü ���
		case 4:
			AccountInformation();
			continue;
		}
	}
	return 0;
}