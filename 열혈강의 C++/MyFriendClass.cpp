#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

class Girl;		// 11�� Boy Ŭ�������� Girl �� Ŭ������°� �˸��� ���� ����

class Boy
{
private: friend class Girl;	// Girl Ŭ������ ģ�� ����
	   int height;

public:
	void ShowYourFriendInfo(Girl& frn);	// 7���� Ŭ���� �������� Girl�� Ŭ������°� ��

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

// ����� ���Ǹ� �и��� ������ GirlŬ������ ������� phNum�� ���縦 �˰� �ϱ� ����
void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

// �̳༮�� ����� ���Ǹ� ���ÿ� �ص� �ȴ� �� ������ BoyŬ���� �Ŀ� GirlŬ������ ���� �Ʊ� ����
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