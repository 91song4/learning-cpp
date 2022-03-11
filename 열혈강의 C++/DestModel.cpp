#include<iostream>	
#include<cstring>
using std::cout;
using std::endl;

class Person
{
private:
	char* name;

public:
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}

public:
	Person(const char* myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
	}

	~Person()
	{
		delete[] name;
	}
};

class UnivStudent : public Person
{
private:
	char* major;

public:
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}

public:
	UnivStudent(const char* myname, const char* mymajor)
		: Person(myname)
	{
		major = new char[strlen(mymajor) + 1];
		strcpy_s(major, strlen(mymajor) + 1, mymajor);
	}
	~UnivStudent()
	{
		delete[] major;
	}
};

int main(void)
{
	UnivStudent st1("Lee", "Computer eng.");
	st1.WhoAreYou();

	UnivStudent st2("Yoon", "Electronic eng.");
	st2.WhoAreYou();
	return 0;
}