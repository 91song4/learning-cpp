#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

class Person
{
private:
	char* name;
	int age;

public:
	void ShowPersonInfo() const
	{
		cout << "?̸?: " << name << endl;
		cout << "????: " << age << endl;
	}

public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}

	Person(const Person& copy)
		: age(copy.age)
	{
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy_s(name, len, copy.name);
	}

	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}