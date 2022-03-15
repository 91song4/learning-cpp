#ifndef __AccountHandler_h__
#define __AccountHandler_h__

#include"Account.h"
class AccountHandler
{
private:
	Account* accArr[100];	// Account ������ ���� �迭
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
	~AccountHandler();
};

#endif