#ifndef __HighCreditAccount_h__
#define __HighCreditAccount_h__

#include"NormalAccount.h"

class HighCreditAccount :public NormalAccount	// 높은 이율의 이자지급 계좌 - 기본이율 9
{
private:
	int interestRate;	// 이자율
	int ratingRate;		// 신용등급에 따른 추가 이자율

public:
	virtual int GetInterestRate() const { return interestRate; }
	int GetRatingRate() const { return ratingRate; }
	virtual void Deposit(int money);
	void ShowAccInfo() const;

public:
	HighCreditAccount(int ID, int money, char* name, int rating);
	// NormalAccount 클래스와 마찬가지로 객체 생성과정에서 기본이율을 등록할 수 있다.
	// 고객의 신용등급을 A, B, C 로 나누고 계좌개설 시 이 정보를 등록한다.
	// A, B, C 등급별로 각각 기본이율에 7%, 4%, 2%의 이율을 추가로 제공한다.
};

#endif