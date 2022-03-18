#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2; // num2에 0이 들어온다면 -> 예외의 발생위치

	if (num2 == 0) // 예외의 발견위치 , if문의 예외처리는 예외처리를 위한 코드인지 논리적기능을 위한 if 문인지 쉽게 파악하기가 힘들다.
	{
		cout << "제수는 0이 될 수 없습니다." << endl; //예외의 처리위치
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	else
	{
	cout << "나눗셈의 몫: " << num1 / num2 << endl;
	cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}
	return 0;
}