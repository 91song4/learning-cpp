#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// 기능 1. 계좌개설
// 기능 2. 입금
// 기능 3. 출금
// 기능 4. 전체고객 잔액조회

// 계좌번호
int id = 99;
char name[100];
int deposit;
int withdraw;
int money;

void Deposit();

class userinfo
{

};
int menu()
{
	int _choose = 0;
	cout << "------Menu-----\n" << "1. 계좌개설\n" << "2. 입 금\n" << "3. 출 금\n" << "4. 계좌정보 전체 출력\n" << "5. 프로그램 종료\n" << "선택: ";
	cin >> _choose;
	return _choose;
}

int check(int _choose)
{
	while (1 > _choose || 5 < _choose)
	{
		cout << "메뉴가 잘못 선택 되었습니다." << endl;
		_choose = menu();
	}
	return _choose;
}

void AccountOpening(int _choose)
{
	
	cout << "[계좌개설]" << endl << "이 름: ";
	cin>>name;
	++id;
	Deposit();
}

void Deposit()
{
	if (99 == id)
	{
		cout << "계좌개설을 해주세요" << endl;
		return;
	}
	cout << "[입  금]" << endl << "계좌ID: " << id << endl << "입금액: ";
	cin >> deposit;
	cout << "입금완료" << endl;
	money += deposit;
}

void Withdraw()
{
	cout << "[출  금]" << endl << "계좌ID: " << id << endl << "잔 액: " << money << endl << "출금액: ";
	cin >> withdraw;
	if (money < withdraw)
		cout << "잔액이 부족합니다." << endl;
	money -= withdraw;
}

void AccountInformation()
{
	cout << "계좌ID: " << id << endl << "이 름: " << name << endl << "잔액: " << money << endl;
}


int main(void)
{
	int choose = 0;
	while (5 != choose)
	{
		choose = menu();
		choose =  check(choose);
		switch (choose)
		{
		//1. 계좌개설
		case 1:
			AccountOpening(choose);
			continue;
		//2. 입 금
		case 2:
			Deposit();
			continue;
		//3. 출 금
		case 3:
			Withdraw();
			continue;
		//4. 계좌정보 전체 출력
		case 4:
			AccountInformation();
			continue;
		}
	}
	return 0;
}