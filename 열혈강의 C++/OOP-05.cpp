#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	char* cusName;	// 고객이름

public:
	int GetAccId() const { return accID; }
	char* GetCusName()
	{
		return cusName;
	}
	void Deposit(int money) { balance += money; }
	int Withdraw(int money);	// 출금액 반환, 부족 시 0 반환
	void ShowAccInfo() const;
	
public:
	Account(int ID, int money, char* name);
	Account(const Account& copy);
	//~Account() { delete[] cusName; }
};

class AccountHandler
{
private:
	Account* accArr[100];	// Account 저장을 위한 배열
	int accNum = 0;			// 저장된Account 수

public:
	void ShowMenu(void);
	void MakeAccount(void) ;
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;

public:
	~AccountHandler()
	{
		for (int i = 0; i < accNum; ++i)
		{
			//char* ptr = accArr[i]->GetCusName();
			delete[] accArr[i]->GetCusName();
			delete[] accArr[i];
		}
	}
};

int main(void)
{
	int choice;
	AccountHandler handle;
	while (1)
	{
		handle.ShowMenu();
		cout << "선택: ";
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

void AccountHandler::ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다.	" << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

int Account::Withdraw(int money)
{
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
}

Account::Account(int ID, int money, char* name)
	: accID(ID)
	, balance(money)
{
	int len = strlen(name) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, name);
}
Account::Account(const Account& copy)
	: accID(copy.accID)
	, balance(copy.balance)
{
	int len = strlen(copy.cusName) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, copy.cusName);
}

