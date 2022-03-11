#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SoSimple
{
public:
	static int simObjCnt;

public:
	SoSimple()
	{
		//simObjCnt = 0;
		++simObjCnt;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;

int main(void)
{
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;	// ��ü�� �������� �ʾ����� static ������ ����
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;		// ��ü�� ���ؼ��� static ������ ����
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;
	return 0;
}

// Ŭ���� ������ private �� ����Ǹ� �ش� Ŭ������ ��ü�鸸 ������ ����
// Ŭ���� ������ public�� ����Ǹ� �ش� Ŭ���� �̸� �Ǵ� ��ü�� �̸��� ���ؼ� ��𼭵� ������ ����
// 23���� ���� static ������ ��ü ���� �������� ������ �� �� �ִ�