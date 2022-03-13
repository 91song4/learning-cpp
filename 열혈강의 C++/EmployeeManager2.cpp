#include<iostream>
#include<cstring>
using std::cout;
using std::endl;


class Employee
{
private:
	char name[100];

public:
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}

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
		/*
		for (int i = 0; i < empNum; ++i)
			empList[i]->ShowSalaryInfo();
		*/
	}

	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; ++i)
			sum += empList[i]->GetPay();
		*/
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
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmplyeeHandler handler;

	// 직원등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();

	return 0;
}