#include"Account.h"
#include"BankingCommonDecl.h"
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
	, cusName(name)
{}
Account::Account(const Account& copy)
	: accID(copy.accID)
	, balance(copy.balance)
	, cusName(copy.cusName)
{}

Account& Account::operator=(const Account& copy)
{
	cusName = copy.cusName;
	accID = copy.accID;
	balance = copy.balance;
	return *this;
}
