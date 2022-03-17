#ifndef __Account_h__
#define __Account_h__
#include"String.h"

class Account
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	String cusName;	// 고객이름

public:
	int GetAccId() const { return accID; }
	virtual void Deposit(int money) { balance += money; }
	int Withdraw(int money);	// 출금액 반환, 부족 시 0 반환
	virtual void ShowAccInfo() const;

public:
	Account& operator=(const Account& copy);

public:
	Account(int ID, int money, char* name);
	Account(const Account& copy);
	~Account() {}
};

#endif