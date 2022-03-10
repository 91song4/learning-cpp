#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SoSimple
{
private:
	int num;

public:
	SoSimple& AddNum(int n)		// 32 -> const 함수가 아니기 때문에 const 객체로 호출 불가능
	{
		num += n;
		return *this;
	}

	void ShowData()	const		// 33 -> const 함수이기 때문에 const 객체로 호출 가능
	{
		cout << "num: " << num << endl;
	}

public:
	SoSimple(int n)
		: num(n)
	{}
};

int main(void)
{
	const SoSimple obj(7);	//const 객체 생성
	SoSimple obj2(7);	//const 객체 생성
	//obj.AddNum(20);
	obj.ShowData();
	return 0;
}