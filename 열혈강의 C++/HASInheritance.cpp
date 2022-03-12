#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Gun
{
private:
	int bullet;	//������ �Ѿ��� ��

public:
	void Shot()
	{
		cout << "BBANG!" << endl;
		--bullet;
	}

public:
	Gun(int bnum)
		: bullet(bnum)
	{}
};

class Police : public Gun
{
private:
	int handcuffs;	// ������ ������ ��

public:
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		--handcuffs;
	}

public:
	Police(int bnum, int bcuff)
		: Gun(bnum)
		, handcuffs(bcuff)
	{}
};

int main(void)
{
	Police pman(5, 3);	// �Ѿ� 5, ���� 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}