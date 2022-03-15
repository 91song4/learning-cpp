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
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ ¸§: " << cusName << endl;
	cout << "ÀÜ ¾×: " << balance << endl;
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
