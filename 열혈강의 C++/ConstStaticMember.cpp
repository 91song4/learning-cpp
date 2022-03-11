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
	cout << "���þ� ����: " << CountryArea::RUSSIA << "km" << endl;
	cout << "ĳ���� ����: " << CountryArea::CANADA << "km" << endl;
	cout << "�߱� ����: " << CountryArea::CHINA << "km" << endl;
	cout << "�ѱ� ����: " << CountryArea::SOUTH_KOREA << "km" << endl;
	return 0;
}

// Ŭ���� ���� ����� const ��������� �ʱ�ȭ�� ������ �̴ϼȶ������� ���ؾ߸� �Ѵ�.
// �׷��� const static���� ����Ǵ� �������(���)�� ����� ���ÿ� �ʱ�ȭ�� �����ϴ�.
// 16~19�� ��ü�� �������� �ʾƵ� �ǰ�, Ŭ�����̸��� ���� ������ �����ϴ�.