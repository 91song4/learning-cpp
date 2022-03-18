#ifndef __AccountHandler_h__
#define __AccountHandler_h__
#include"BoundCheckArray.h"
#include"Account.h"

class AccountHandler
{
private:
	BoundCheckArray<Account> accArr;	// Account ������ ���� �迭
	int accNum = 0;			// �����Account ��

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