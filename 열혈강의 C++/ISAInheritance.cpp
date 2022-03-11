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
		cout << "��û ������ ����մϴ�." << endl;
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
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
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
			cout << "������ �ʿ��մϴ�." << endl;	
			return;
		}

		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}

		cout << "�ʱ� ������ ó���մϴ�." << endl;
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
	NotebookComp nc("�̼���", 5);
	TabletNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}