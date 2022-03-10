#include<iostream>
using std::cin;
using std::cout;
using std::endl;

namespace COMP_POS
{
	enum
	{
		CLERK, SENIOR, ASSIST, MANAGER	//사원, 주임, 대리, 과장
	};
}

class NameCard
{
private:
	char* name;
	char* company;
	char* phone;
	int rank;

public:
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		switch (rank)
		{
		case 0:
			cout << "직급: 사원" << endl << endl;
			break;
		case 1:
			cout << "직급: 주임" << endl << endl;
			break;
		case 2:
			cout << "직급: 대리" << endl << endl;
			break;
		case 3:
			cout << "직급: 과장" << endl << endl;
			break;
		}
	}

public:
	NameCard(const char* _name, const char* _company, const char* _phone, int _rank)
	{
		int len = strlen(_name) + 1;
		name = new char[len];
		strcpy_s(name, len, _name);

		len = strlen(_company) + 1;
		company = new char[len];
		strcpy_s(company, len, _company);

		len = strlen(_phone) + 1;
		phone = new char[len];
		strcpy_s(phone, len, _phone);

		rank = _rank;
	}

	NameCard(const NameCard& copy)
		: rank(copy.rank)
	{
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);

		len = strlen(copy.company) + 1;
		company = new char[len];
		strcpy_s(company, len, copy.company);

		len = strlen(copy.phone) + 1;
		phone = new char[len];
		strcpy_s(phone, len, copy.phone);
	}

	~NameCard()
	{
		delete[] name;
		delete[] company;
		delete[] phone;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSECIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSECIOR;
	manClerk.ShowNameCardInfo();
	copy1.ShowNameCardInfo();
	manSECIOR.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}