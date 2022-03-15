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

// 디폴트 대입연산자를 사용하면 메모리누수가 생긴다.
// 해결법은 대입연산자 오버로딩을 직접 정의해서 깊은복사를 한다.