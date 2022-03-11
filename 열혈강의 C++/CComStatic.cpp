#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void Counter()
{
	static int cnt;
	++cnt;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; ++i)
		Counter();
	return 0;
}

// C언어에서의 static 개념
// 전역변수에 선언된 static의 의미 - 선언된 파일 내에서만 참조를 허용하겠다는 의미
// 함수 내에 선언된 static의 의미 - 한번만 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다.