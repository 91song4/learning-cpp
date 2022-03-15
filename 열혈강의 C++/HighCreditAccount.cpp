#include"HighCreditAccount.h"
#include"BankingCommonDecl.h"

void HighCreditAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money * ((interestRate + ratingRate) / 100.0));
}

void HighCreditAccount::ShowAccInfo() const
{
	NormalAccount::ShowAccInfo();
	cout << "추가 이율: " << GetRatingRate() << "%" << endl;
}

HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int rating)
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