#include<iostream>
using std::cout;
using std::endl;

template <class T1, class T2> // 둘 이상의 템플릿 타입을 명시할 수 있다.
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl; // 형 변환을 통해서 출력
}

int main(void)
{
	// 함수템플릿의 매개변수형이 double로 선언되었기 때문에 전달되는 인자를 통해서 T1, T2의 자료형을 결정하지 못한다
	// 그러므로 템플릿함수의 호출형식을 명시적으로 해주어야한다 
	// ex) ShowData<(T1, T2)>()
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}