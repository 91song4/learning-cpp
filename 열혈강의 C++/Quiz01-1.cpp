#include <iostream>


// 문제 1
// 사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해 보자. 단, 프로그램의 실행은 다음과 같이 이뤄져야 한다.
void Quiz1()
{
	int a1, a2, a3, a4, a5;

	std::cout << "1번째 정수 입력: ";
	std::cin >> a1;
	std::cout << "2번째 정수 입력: ";
	std::cin >> a2;
	std::cout << "3번째 정수 입력: ";
	std::cin >> a3;
	std::cout << "4번째 정수 입력: ";
	std::cin >> a4;
	std::cout << "5번째 정수 입력: ";
	std::cin >> a5;
	
	int sum = a1 + a2 + a3 + a4 + a5;
	std::cout << "합계: " << sum << std::endl;
}
// 문제 2
// 프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성해보자.
void Quiz2()
{
	char name[100];
	char phone[100];

	std::cout << "이름이 무엇입니까?: ";
	std::cin >> name;

	std::cout << "전화번호가 무엇입니까?: ";
	std::cin >> phone;

	std::cout << "이름: " << name << " 전화번호: " << phone << std::endl;
}
// 문제 3
// 숫자를 하나 입력받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해 보자. 예를 들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력해야 한다.
void Quiz3()
{
	int num;
	std::cout << "구구단 몇단이 궁금하신가요? : ";
	std::cin >> num;

	for (int i = 0; i < 9; ++i)
	{
		int gugu = num * (i + 1);
		std::cout << num << " x " << i + 1 << " = " << gugu << std::endl;
	}
}
// 문제 4
// 판매원들의 급여 계산 프로그램을 작성해 보자. 이 회사는 모든 판매원에게 매달 50만원의 기본 급여와 물품 판매 가격의 12%에 해당하는 돈을 지급한다. 예를 들어서 민수라는 친구의 이번 달 물품 판매 금액이 100만원이라면, 50+100*0.12=62, 따라서 62만원을 급여로 지급 받는다. 단, 아래의 실행의 예에서 보이듯이 이러한 급여의 계산은 -1이 입력될 때까지 계속 되어야 한다.
void Quiz4()
{
	while (true)
	{
		int sell;
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> sell;
		if (-1 == sell)
			break;
		sell *=  0.12;
		std::cout << "이번 달 급여: " << 50 + sell << "만원\n";
	}
	std::cout << "프로그램을 종료합니다.";
}

int main(void)
{
	Quiz1();
	Quiz2();
	Quiz3();
	Quiz4();

	return 0;
}