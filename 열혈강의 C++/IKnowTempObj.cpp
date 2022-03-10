#include<iostream>
using std::cout;
using std::endl;

class Temporary
{
private:
	int num;

public:
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}

public:
	Temporary(int n)
		: num(n)
	{
		cout << "create obj: " << num << endl;
	}

	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
};

int main(void)
{
	// 접근이 불가능하게 된 임시객체는 다음행으로 넘어가면 소멸이 된다
	Temporary (100);	// 임시객체에 접근할수있는 변수가 없어 종료.
	Temporary obj(100);	// 변수 obj을 통해 접근 가능.
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);	// 임시객체를 참조하는 참조자 ref를 통해 접근 가능.
	cout << "********** end of main!" << endl << endl;

	return 0;
}