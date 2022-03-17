#ifndef __Account_h__
#define __Account_h__
#include"String.h"

class Account
{
private:
	int accID;		// ���¹�ȣ
	int balance;	// �ܾ�
	String cusName;	// ���̸�

public:
	int GetAccId() const { return accID; }
	virtual void Deposit(int money) { balance += money; }
	int Withdraw(int money);	// ��ݾ� ��ȯ, ���� �� 0 ��ȯ
	virtual void ShowAccInfo() const;

public:
	Account& operator=(const Account& copy);

public:
	Account(int ID, int money, char* name);
	Account(const Account& copy);
	~Account() {}
};

#endif