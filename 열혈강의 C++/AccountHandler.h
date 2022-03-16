#ifndef __AccountHandler_h__
#define __AccountHandler_h__

#include"AccountArray.h"
class AccountHandler
{
private:
	AccountArray accArr;	// Account 저장을 위한 배열
	int accNum = 0;			// 저장된Account 수

public:
	void ShowMenu(void);
	void MakeAccount(void);
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;

public:
	AccountHandler();
	~AccountHandler();
};

#endif