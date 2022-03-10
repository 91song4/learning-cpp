#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// 문제 1. 참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하여라.
//	-> 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
//	-> 인자로 전달된 int형 변수의 부호를 바꾸는 함수

// 문제 2. 앞서 소개한 예제 RefSwap.cpp의 SwapByRef2 함수를 다음의 형태로 호출하면 컴파일 에러가 발생한다.
// SwapByRef2(23,45);
// 컴파일 에러가 발생하는 이유가 무엇인지 설명해보자.
// 상수를 대상으로 참조자선언할 수는 없다.

// 문제 3. 문제의 제시에 앞서 먼저 다음 코드를 보자.

void Increase(int& _num)
{
	++_num;
}

void PlusMinus(int& _num)
{
	_num *= -1;
}

void SwapPointer(int*& _ptr1, int*& _ptr2)
{
	int* temp = _ptr1;
	_ptr1 = _ptr2;
	_ptr2 = temp;
}

int main(void)
{
	// 문제 1.
	{
		int num = 2;

		Increase(num);
		cout << num << endl;

		PlusMinus(num);
		cout << num << endl;
	}

	//문제 3.
	{
		int num1 = 5;
		int* ptr1 = &num1;

		int num2 = 10;
		int* ptr2 = &num2;

		SwapPointer(ptr1, ptr2);
		cout << *ptr1 << endl;
		cout << *ptr2 << endl;
	}
	return 0;
}