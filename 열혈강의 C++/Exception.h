#ifndef __Exception_h__
#define __Exception_h__
#include"BankingCommonDecl.h"

class DepositException
{
public:
	void ShowExceptionReason()
	{
		cout << "입금액을 확인해주세요." << endl;
	}
};

class WithdrawException
{
public:
	void ShowExceptionReason()
	{
		cout << "잔액부족" << endl << endl;
	}
};

#endif // !__Exception_h__
