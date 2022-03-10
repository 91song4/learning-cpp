#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

class Girl;		// 11행 Boy 클래스에게 Girl 이 클래스라는걸 알리기 위한 선언

class Boy
{
private: friend class Girl;	// Girl 클래스를 친구 선언
	   int height;

public:
	void ShowYourFriendInfo(Girl& frn);	// 7행의 클래스 선언으로 Girl이 클래스라는걸 암

public:
	Boy(int len)
		: height(len)
	{}
};

class Girl
{
private: friend class Boy;
	char phNum[20];

public:
	void ShowYourFriendInfo(Boy& frn);

public:
	Girl(const char* num)
	{
		strcpy_s(phNum, num);
	}
};

// 선언과 정의를 분리한 이유는 Girl클래스의 멤버변수 phNum의 존재를 알게 하기 위함
void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

// 이녀석은 선언과 정의를 동시에 해도 된다 그 이유는 Boy클래스 후에 Girl클래스가 정의 됐기 때문
void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}