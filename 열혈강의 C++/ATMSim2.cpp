#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class DepositException :public AccountException
{
private:
	int reqDep; // ??û ?Աݾ?

public:
	void ShowExceptionReason()
	{
		cout << "[???? ?޽???: " << reqDep << "?? ?ԱݺҰ?]" << endl;
	}

public:
	DepositException(int money)
		: reqDep(money)
	{}
};

class WithdrawException :public AccountException
{
private:
	int balance; // ?ܰ?

public:
	void ShowExceptionReason()
	{
		cout << "[???? ?޽???: ?ܾ?" << balance << ", ?ܾ׺???]" << endl;
	}

public:
	WithdrawException(int money)
		: balance(money)
	{}
};

class Account
{
private:
	char accNum[50];
	int balance; // ?ܰ?

public:
	void Deposit(int money) throw(AccountException)
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}

	void Withdraw(int money) throw(AccountException)
	{
		if (money > balance)
			throw WithdrawException(balance);
		balance -= money;
	}

	void ShowMyMoney()
	{
		cout << "?ܰ?: " << balance << endl << endl;
	}

public:
	Account(const char* acc, int money)
		: balance(money)
	{
		strcpy_s(accNum, acc);
	}
};

int main(void)
{
	Account myAcc("56789-827120", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	return 0;
}