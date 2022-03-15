#ifndef __HighCreditAccount_h__
#define __HighCreditAccount_h__

#include"NormalAccount.h"

class HighCreditAccount :public NormalAccount	// ���� ������ �������� ���� - �⺻���� 9
{
private:
	int interestRate;	// ������
	int ratingRate;		// �ſ��޿� ���� �߰� ������

public:
	virtual int GetInterestRate() const { return interestRate; }
	int GetRatingRate() const { return ratingRate; }
	virtual void Deposit(int money);
	void ShowAccInfo() const;

public:
	HighCreditAccount(int ID, int money, char* name, int rating);
	// NormalAccount Ŭ������ ���������� ��ü ������������ �⺻������ ����� �� �ִ�.
	// ���� �ſ����� A, B, C �� ������ ���°��� �� �� ������ ����Ѵ�.
	// A, B, C ��޺��� ���� �⺻������ 7%, 4%, 2%�� ������ �߰��� �����Ѵ�.
};

#endif