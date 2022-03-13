#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

namespace RISK_LEVEL
{
	enum
	{
		RISK_A,
		RISK_B,
		RISK_C,
	};
}

class Employee
{
private:
	char name[100];

public:
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}

	virtual int GetPay() const = 0;

	virtual void ShowSalaryInfo() const = 0;

public:
	Employee(const char* name)
	{
		strcpy_s(this->name, name);
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;		// 월 급여

public:
	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}

public:
	PermanentWorker(const char* name, int money)
		: salary(money)
		, Employee(name)
	{}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;	// 이 달에 일한 시간의 합계
	int payPerHour;	// 시간당 급여

public:
	void AddWorkTime(int time)	// 일한 시간의 추가
	{
		workTime += time;
	}

	int GetPay() const	//이 달의 급여
	{
		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}

public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name)
		, workTime(0)
		, payPerHour(pay)
	{}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;	// 월 판매실적
	double bonusRatio;	// 상여금 비율	

public:
	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}

public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money)
		, salesResult(0)
		, bonusRatio(ratio)
	{}
};

class ForeignSalesWorker : public SalesWorker
{
private:
	int risk;

public:
	int GetPay() const
	{
		switch (risk)
		{
		case RISK_LEVEL::RISK_A:
			return SalesWorker::GetPay() * 0.3;
		case RISK_LEVEL::RISK_B:
			return SalesWorker::GetPay() * 0.2;
		case RISK_LEVEL::RISK_C:
			return SalesWorker::GetPay() * 0.1;
		}
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetPay() << endl;
		cout << "sum: " << SalesWorker::GetPay() + GetPay() << endl << endl;
	}


public:
	ForeignSalesWorker(const char* name, int money, double ratio, int _risk)
		: SalesWorker(name, money, ratio)
		, risk(_risk)
	{}
};

class EmplyeeHandler
{
private:
	Employee* empList[50];
	int empNum;

public:
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; ++i)
			empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; ++i)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}

public:
	EmplyeeHandler()
		: empNum(0)
	{}

	~EmplyeeHandler()
	{
		for (int i = 0; i < empNum; ++i)
			delete empList[i];
	}
};

int main(void)
{
	EmplyeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}