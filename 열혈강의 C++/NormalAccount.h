#ifndef __NormalAccount_h__
#define __NormalAccount_h__

#include"Account.h"
class NormalAccount :public Account	// 최소한의 이자지급 계좌 - 기본이율 3
{
private:
	int interestRate;	// 이자율

public:
	virtual int GetInterestRate() const { return interestRate; }
	virtual void Deposit(int money);
	virtual void ShowAccInfo() const;

public:
	NormalAccount(int ID, int money, char* name); // 생성자를 통해서 이율정보(이자비율의 정보)를 등록할 수 있도록 정의
};

#endif