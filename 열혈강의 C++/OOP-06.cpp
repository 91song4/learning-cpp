#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
namespace RATING
{
	enum { A = 1, B, C };
}
class Account
{
private:
	int accID;		// ���¹�ȣ
	int balance;	// �ܾ�
	char* cusName;	// ���̸�

public:
	int GetAccId() const { return accID; }
	virtual void Deposit(int money) { balance += money; }
	int Withdraw(int money);	// ��ݾ� ��ȯ, ���� �� 0 ��ȯ
	virtual void ShowAccInfo() const;

public:
	Account(int ID, int money, char* name);
	Account(const Account& copy);
	~Account() { delete[] cusName; }
};

class NormalAccount :public Account	// �ּ����� �������� ���� - �⺻���� 3
{
private:
	int interestRate;	// ������

public:
	virtual int GetInterestRate() const { return interestRate; }
	virtual void Deposit(int money);
	virtual void ShowAccInfo() const;

public:
	NormalAccount(int ID, int money, char* name) // �����ڸ� ���ؼ� ��������(���ں����� ����)�� ����� �� �ֵ��� ����
		: Account(ID, money, name)
		, interestRate(3)
	{}
};

class HighCreditAccount :public NormalAccount	// ���� ������ �������� ���� - �⺻���� 9
{
private:
	int interestRate;	// ������
	int ratingRate;		// �ſ��޿� ���� �߰� ������

public:
	virtual int GetInterestRate() const { return interestRate; }
	int GetRatingRate() const { return ratingRate; }
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money*((interestRate+ ratingRate)/100.0));
	}
	void ShowAccInfo() const;

public:
	HighCreditAccount(int ID, int money, char* name, int rating)
		: NormalAccount(ID, money, name)
		, interestRate(9)
	{
		switch (rating)
		{
		case RATING::A:
			ratingRate = 7;
			break;
		case RATING::B:
			ratingRate = 4;
			break;
		case RATING::C:
			ratingRate = 2;
			break;
		}
	}
	// NormalAccount Ŭ������ ���������� ��ü ������������ �⺻������ ����� �� �ִ�.
	// ���� �ſ����� A, B, C �� ������ ���°��� �� �� ������ ����Ѵ�.
	// A, B, C ��޺��� ���� �⺻������ 7%, 4%, 2%�� ������ �߰��� �����Ѵ�.
};

class AccountHandler
{
private:
	Account* accArr[100];	// Account ������ ���� �迭
	int accNum = 0;			// �����Account ��

public:
	void ShowMenu(void);
	void MakeAccount(void);
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;

public:
	~AccountHandler()
	{
		for (int i = 0; i < accNum; ++i)
		{
			delete accArr[i];
		}
	}
};

int main(void)
{
	int choice;
	AccountHandler handle;
	while (1)
	{
		handle.ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			handle.MakeAccount();
			break;
		case DEPOSIT:
			handle.DepositMoney();
			break;
		case WITHDRAW:
			handle.WithdrawMoney();
			break;
		case INQUIRE:
			handle.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}

void AccountHandler::ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int choice;
	cout << "[������������]" << endl;
	cout << "1.���뿹������ 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		cout << "Illegal selection.." << endl;
	}
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name);
}

void AccountHandler::MakeHighCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int rating;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> rating;
	cout << endl;

	accArr[accNum++] = new HighCreditAccount(id, balance, name, rating);
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�.	" << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

int Account::Withdraw(int money)
{
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}
}

void Account::ShowAccInfo() const
{
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
}

Account::Account(int ID, int money, char* name)
	: accID(ID)
	, balance(money)
{
	int len = strlen(name) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, name);
}
Account::Account(const Account& copy)
	: accID(copy.accID)
	, balance(copy.balance)
{
	int len = strlen(copy.cusName) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, copy.cusName);
}

void NormalAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money * (interestRate / 100.0));
}

void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "����: " << GetInterestRate() <<"%" << endl;
}

void HighCreditAccount::ShowAccInfo() const
{
	NormalAccount::ShowAccInfo();
	cout << "�߰� ����: " << GetRatingRate() << "%" << endl;
}
