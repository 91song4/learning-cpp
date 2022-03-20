#ifndef __AccountHandler_h__
#define __AccountHandler_h__
#include"Account.h"
#include"BoundCheckArray.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"Exception.h"


class AccountHandler
{
private:
	BoundCheckArray<Account> accArr;	// Account 저장을 위한 배열
	int accNum = 0;			// 저장된Account 수

public:
	void ShowMenu(void);
	void MakeAccount(void);
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
	void DepositMoney(void) throw(DepositException);
	void WithdrawMoney(void) throw(WithdrawException);
	void ShowAllAccInfo(void) const;

public:
	AccountHandler();
	~AccountHandler();
};

#endif