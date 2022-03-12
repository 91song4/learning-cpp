#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Gun
{
private:
	int bullet;

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

class Police
{
private:
	int handcuffs;
	Gun* pistol;

public:
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		--handcuffs;
	}

	void Shot()
	{
		if (NULL == pistol)
			cout << "Hut BBANG" << endl;
		else
			pistol->Shot();
	}

public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (0 < bnum)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	~Police()
	{
		delete[] pistol;
	}
};

int main(void)
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);		// 권총을 소유하지 않은 경찰
	pman2.Shot();
	pman2.PutHandcuff();


	return 0;
}