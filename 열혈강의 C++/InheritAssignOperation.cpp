#include<iostream>
using std::cout;
using std::endl;

class First
{
private:
	int num1, num2;

public:
	void ShowData()
	{
		cout << num1 << ", " << num2 << endl;
	}

public:
	First& operator =(const First& ref)
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}

public:
	First(int n1 = 0, int n2 = 0)
		: num1(n1)
		, num2(n2)
	{}
};

class Second : public First
{
private:
	int num3, num4;

public:
	void ShowData()
	{
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}

public:
	Second& operator =(const Second& ref)
	{
		cout << "Second& operator=()" << endl;
		//First::operator=(ref);	// 해결점: 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입한다.
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}

public:
	Second(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0)
		: num3(n3)
		, num4(n4)
		, First(n1, n2)
	{}
};

int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();
	return 0;
}

// 유도 클래스의 대입 연산자 정의에서, 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않으면
// 기초 클래스의 대입 연산자는 호출되지 않아서, 기초 클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외된다.
// 48행 : 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입한다.