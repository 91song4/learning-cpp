#include<iostream>
using std::cout;
using std::endl;

class CountryArea
{
public:
	const static int RUSSIA			=1707540;
	const static int CANADA			=998467;
	const static int CHINA			=957290;
	const static int SOUTH_KOREA	=9922;
};

int main(void)
{
	cout << "러시아 면적: " << CountryArea::RUSSIA << "km" << endl;
	cout << "캐나다 면적: " << CountryArea::CANADA << "km" << endl;
	cout << "중국 면적: " << CountryArea::CHINA << "km" << endl;
	cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "km" << endl;
	return 0;
}

// 클래스 내에 선언된 const 멤버변수의 초기화는 생성자 이니셜라이저를 통해야만 한다.
// 그러나 const static으로 선언되는 멤버변수(상수)는 선언과 동시에 초기화가 가능하다.
// 16~19행 객체를 생성하지 않아도 되고, 클래스이름을 통해 접근이 가능하다.