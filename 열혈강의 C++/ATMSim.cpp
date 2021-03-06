#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class DepositException
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

class WithdrawException
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
	void Deposit(int money) throw(DepositException)
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}

	void Withdraw(int money) throw(WithdrawException)
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
	catch (DepositException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (WithdrawException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	return 0;
}