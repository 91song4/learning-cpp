#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
namespace RATING
{
	enum { A = 1, B, C };
}
class Account
{
private:
	int accID;		// 계좌번호
	int balance;	// 잔액
	char* cusName;	// 고객이름

public:
	int GetAccId() const { return accID; }
	virtual void Deposit(int money) { balance += money; }
	int Withdraw(int money);	// 출금액 반환, 부족 시 0 반환
	virtual void ShowAccInfo() const;

public:
	Account(int ID, int money, char* name);
	Account(const Account& copy);
	~Account() { delete[] cusName; }
};

class NormalAccount :public Account	// 최소한의 이자지급 계좌 - 기본이율 3
{
private:
	int interestRate;	// 이자율

public:
	virtual int GetInterestRate() const { return interestRate; }
	virtual void Deposit(int money);
	virtual void ShowAccInfo() const;

public:
	NormalAccount(int ID, int money, char* name) // 생성자를 통해서 이율정보(이자비율의 정보)를 등록할 수 있도록 정의
		: Account(ID, money, name)
		, interestRate(3)
	{}
};

class HighCreditAccount :public NormalAccount	// 높은 이율의 이자지급 계좌 - 기본이율 9
{
private:
	int interestRate;	// 이자율
	int ratingRate;		// 신용등급에 따른 추가 이자율

public:
	virtual int GetInterestRate() const { return interestRate; }
	int GetRatingRate() const { return ratingRate; }
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money*((interestRate+ ratingRate)/100.0));
	}
	void ShowAccInfo() const;

public:
	HighCreditAccount(int ID, int money, char* name, int rating)
		: NormalAccount(ID, money, name)
		, interestRate(9)
	{
		switch (rating)
		{
		case RATING::A:
			ratingRate = 7;
			break;
		case RATING::B:
			ratingRate = 4;
			break;
		case RATING::C:
			ratingRate = 2;
			break;
		}
	}
	// NormalAccount 클래스와 마찬가지로 객체 생성과정에서 기본이율을 등록할 수 있다.
	// 고객의 신용등급을 A, B, C 로 나누고 계좌개설 시 이 정보를 등록한다.
	// A, B, C 등급별로 각각 기본이율에 7%, 4%, 2%의 이율을 추가로 제공한다.
};

class AccountHandler
{
private:
	Account* accArr[100];	// Account 저장을 위한 배열
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
	~AccountHandler()
	{
		for (int i = 0; i < accNum; ++i)
		{
			delete accArr[i];
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
	int choice;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예끔계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		cout << "Illegal selection.." << endl;
	}
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name);
}

void AccountHandler::MakeHighCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int rating;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> rating;
	cout << endl;

	accArr[accNum++] = new HighCreditAccount(id, balance, name, rating);
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

void NormalAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money * (interestRate / 100.0));
}

void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "이율: " << GetInterestRate() <<"%" << endl;
}

void HighCreditAccount::ShowAccInfo() const
{
	NormalAccount::ShowAccInfo();
	cout << "추가 이율: " << GetRatingRate() << "%" << endl;
}
