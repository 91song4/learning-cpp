#include<iostream>
using std::cout;
using std::endl;

class First
{
private:
	char* strOne;

public:
	First(const char* str)
		: strOne(new char[strlen(str) + 1])
	{}

	/*~First()
	{
		cout << "~First()" << endl;
		delete[] strOne;
	}*/
	virtual ~First()
	{
		cout << "~First()" << endl;
		delete[] strOne;
	}
};

class Second : public First
{
private:
	char* strTwo;

public:
	Second(const char* str1, const char* str2)
		: First(str1)
		, strTwo(new char[strlen(str2) + 1])
	{}

	~Second()
	{
		cout << "~Second()" << endl;
	delete[] strTwo;
	}
};

int main(void)
{
	First* ptr = new Second("simple", "complex");
	delete ptr;
	return 0;
}

// Second 클래스의 소멸자가 호출되지 않는다.
// 가상소멸자를 선언하여 소멸자를 모두 호출한다.