#include"Account.h"
#include"NormalAccount.h"
#include"HighCreditAccount.h"
#include"AccountHandler.h"
#include"BankingCommonDecl.h"

int main(void)
{
	int choice;
	AccountHandler handle;
	while (1)
	{
		handle.ShowMenu();
		cout << "¼±ÅÃ: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			handle.MakeAccount();
			break;
		case DEPOSIT:
			handle.DepositMoney();
			break;
		case WITHDRAW:
			handle.WithdrawMoney();
			break;
		case INQUIRE:
			handle.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}

