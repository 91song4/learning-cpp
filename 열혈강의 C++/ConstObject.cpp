#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SoSimple
{
private:
	int num;

public:
	SoSimple& AddNum(int n)		// 32 -> const �Լ��� �ƴϱ� ������ const ��ü�� ȣ�� �Ұ���
	{
		num += n;
		return *this;
	}

	void ShowData()	const		// 33 -> const �Լ��̱� ������ const ��ü�� ȣ�� ����
	{
		cout << "num: " << num << endl;
	}

public:
	SoSimple(int n)
		: num(n)
	{}
};

int main(void)
{
	const SoSimple obj(7);	//const ��ü ����
	SoSimple obj2(7);	//const ��ü ����
	//obj.AddNum(20);
	obj.ShowData();
	return 0;
}