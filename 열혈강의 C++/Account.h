#ifndef __Account_h__
#define __Account_h__
class Account
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	char* cusName;	// 고객이름

public:
	int GetAccId() const { return accID; }
	virtual void Deposit(int money) { balance += money; }
	int Withdraw(int money);	// 출금액 반환, 부족 시 0 반환
	virtual void ShowAccInfo() const;

public:
	Account(int ID, int money, char* name);
	Account(const Account& copy);
	~Account() { delete[] cusName; }
};

#endif