#include<iostream>
using std::cout;
using std::endl;

template <typename T>
T Add(T num1, T num2)
{
	return num1+num2;
}

int main(void)
{
	// 함수이름에 자료형을 전달하여 호출하면 전달받는 인자를 전달한 자료형으로 변환시킨다 그래서 16행은 손실이 발생한다.
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;

	// 함수이름에 자료형을 전달하지 않으면 인자의 자료형을 참조하여 자료형을 전달한다. 16행과 22행은 여기서 차이가 발생한다.
	cout << Add(15, 20) << endl;
	cout << Add(2.9, 3.7) << endl;
	cout << Add(3.2, 3.2) << endl;
	cout << Add(3.14, 2.75) << endl;
	return 0;
}