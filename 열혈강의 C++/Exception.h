#ifndef __Exception_h__
#define __Exception_h__
#include"BankingCommonDecl.h"

class DepositException
{
public:
	void ShowExceptionReason()
	{
		cout << "�Աݾ��� Ȯ�����ּ���." << endl;
	}
};

class WithdrawException
{
public:
	void ShowExceptionReason()
	{
		cout << "�ܾ׺���" << endl << endl;
	}
};

#endif // !__Exception_h__
