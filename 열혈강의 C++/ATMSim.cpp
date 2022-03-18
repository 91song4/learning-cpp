#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class DepositException
{
private:
	int reqDep; // 요청 입금액
	
public:
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}

public:
	DepositException(int money)
		: reqDep(money)
	{}
};

class WithdrawException
{
private:
	int balance; // 잔고

public:
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액" << balance << ", 잔액부족]" << endl;
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
	int balance; // 잔고

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
		cout << "잔고: " << balance << endl << endl;
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