#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x, int y)
		: xpos(x)
		, ypos(y)
	{}

	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point center;
	int radius;

public:
	Circle(int _xpos, int _ypos, int _radius)
		: center(_xpos, _ypos)
		, radius(_radius)
	{}

	void ShowCircleInfo()
	{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle innerCircle;
	Circle outterCircle;

public:
	Ring(int _xpos, int _ypos, int _radius, int _xpos2, int _ypos2, int _radius2)
		: innerCircle(_xpos, _ypos, _radius)
		, outterCircle(_xpos2, _ypos2, _radius2)
	{}

	void ShowRingInfo()
	{
		cout << "Inner Circle Info..." << endl;
		innerCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outterCircle.ShowCircleInfo();
	}
};

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
	~NameCard()
	{
		delete[] name;
		delete[] company;
		delete[] phone;
	}
};

int main(void)
{
	// 문제 1.
	/*{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	}*/

	// 문제 2.
	{
		NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
		NameCard manSECIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
		NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
		manClerk.ShowNameCardInfo();
		manSECIOR.ShowNameCardInfo();
		manAssist.ShowNameCardInfo();
	}
	return 0;
}