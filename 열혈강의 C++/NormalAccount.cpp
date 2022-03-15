#include"NormalAccount.h"
#include"BankingCommonDecl.h"

void NormalAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money * (interestRate / 100.0));
}

void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "ÀÌÀ²: " << GetInterestRate() << "%" << endl;
}

NormalAccount::NormalAccount(int ID, int money, char* name)
	: Account(ID, money, name)
	, interestRate(3)
{}
