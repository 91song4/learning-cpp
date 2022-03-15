#include<iostream>
#include<cstring>
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
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

//public:
//	Person& operator=(const Person& ref)
//	{
//		delete[] name;
//		name = new char[strlen(ref.name) + 1];
//		strcpy_s(name, strlen(ref.name) + 1, ref.name);
//		age = ref.age;
//		return *this;
//	}

public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
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
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}