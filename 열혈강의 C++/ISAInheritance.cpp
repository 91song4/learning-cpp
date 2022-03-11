#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Computer
{
private:
	char owner[50];

public:
	void Calculate()
	{
		cout << "요청 내용을 계산합니다." << endl;
	}

public:
	Computer(const char* name)
	{
		strcpy_s(owner, name);
	}

};

class NotebookComp : Computer
{
private:
	int Battery;

public:
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }

public:
	NotebookComp(const char* name, int initChag)
		: Computer(name)
		, Battery(initChag)
	{}

};

class TabletNotebook : NotebookComp
{
private:
	char regstPenModel[50];

public:
	void Write(const char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << endl;	
			return;
		}

		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}

		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}

public:
	TabletNotebook(const char* name, int initChag, const char* pen)
		:NotebookComp(name, initChag)
	{
		strcpy_s(regstPenModel, pen);
	}
};

int main(void)
{
	NotebookComp nc("이수종", 5);
	TabletNotebook tn("정수영", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}