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
			try
			{
				handle.DepositMoney();
				break;
			}
			catch (DepositException& expn)
			{
				expn.ShowExceptionReason();
				break;
			}
		case WITHDRAW:
			try
			{
				handle.WithdrawMoney();
				break;
			}
			catch (WithdrawException& expn)
			{
				expn.ShowExceptionReason();
				break;
			}
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

