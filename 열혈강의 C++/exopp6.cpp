#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

class Account
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	char* cusName;	// 고객이름

public:
	int GetAccId() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;

public:
	Account(int ID, int money, char* name);
	Account(const Account& ref);
	~Account();
};

class NormalAccount :public Account	// 최소한의 이자지급 계좌 - 기본이율 3
{
private:
	int interRate;	// 이자율

public:
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));
	}

public:
	NormalAccount(int ID, int money, char* name, int rate) // 생성자를 통해서 이율정보(이자비율의 정보)를 등록할 수 있도록 정의
		: Account(ID, money, name)
		, interRate(rate)
	{}
};

class HighCreditAccount :public NormalAccount	// 높은 이율의 이자지급 계좌 - 기본이율 9
{
private:
	int specialRate;

public:
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money * (specialRate / 100.0));
	}

public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special)
		: NormalAccount(ID, money, name, rate)
		, specialRate(special)
	{}
};

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;

public:
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;

protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);

public:
	AccountHandler();
	~AccountHandler();

};

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}

void AccountHandler::ShowMenu(void) const
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
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예끔계좌 ";
	cout<< "2.신용신뢰계좌 " << endl;
	cout << "선택: ";
	cin >> sel;
	
	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int rating;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입   금]" << endl;
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
	cout << "[출   금]" << endl;
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

AccountHandler::AccountHandler():accNum(0)
{}

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; ++i)
		delete accArr[i];
}

int Account::GetAccId() const { return accID; }

void Account::Deposit(int money)
{
	balance += money;
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
Account::Account(const Account& ref)
	: accID(ref.accID)
	, balance(ref.balance)
{
	int len = strlen(ref.cusName) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, ref.cusName);
}

Account::~Account()
{
	delete[] cusName;
}