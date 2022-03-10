#include <iostream>

// 문제 1
// 예제 DefaultValue3.cpp에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌, '함수 오버로딩'의 형태로 재 구현해보자. 물론 main 함수는 변경하지 않아야 하며, 실행결과도 동일해야 한다.
int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}

int BoxVolume(int length, int width)
{
	return length * width * 1;
}

int BoxVolume(int length)
{
	return length * 1 * 1;
}

// 문제 2
// 다음과 같은 형태로의 함수 오버로딩은 문제가 있다. 어떠한 문제가 있는지 설명해보자.
int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}
// SimpleFunc()로 호출할 경우 어떤함수를 호출해야할지 알 수 없다.

int main(void)
{

	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	//std::cout << "[D, D, D] : " << BoxVolume() << std::endl;

	return 0;
}
