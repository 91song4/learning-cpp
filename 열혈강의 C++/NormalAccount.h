#ifndef __NormalAccount_h__
#define __NormalAccount_h__

#include"Account.h"
class NormalAccount :public Account	// �ּ����� �������� ���� - �⺻���� 3
{
private:
	int interestRate;	// ������

public:
	virtual int GetInterestRate() const { return interestRate; }
	virtual void Deposit(int money);
	virtual void ShowAccInfo() const;

public:
	NormalAccount(int ID, int money, char* name); // �����ڸ� ���ؼ� ��������(���ں����� ����)�� ����� �� �ֵ��� ����
};

#endif