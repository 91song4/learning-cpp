#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Gun
{
private:
	int bullet;

public:
	/*int GetBullet() const
	{
		return bullet;
	}*/
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
	Police& operator=(const Police& ref) 
	{
		delete[] pistol;
		//pistol = new Gun(ref.pistol->GetBullet());
		pistol = new Gun(*(ref.pistol));	// 답안 - 느낀점 : 데이터로 직접 접근 GetBullet() 함수를 새로 만들지 않아도 됌.
		handcuffs = ref.handcuffs;
		return *this;
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

	Police(Police& copy)
		: handcuffs(copy.handcuffs)
	{
		if (NULL == copy.pistol)
			pistol = NULL;
		else
		{
			//pistol = new Gun(copy.pistol->GetBullet());
			pistol = new Gun(*(copy.pistol));		// 답안 - 느낀점 : 데이터로 직접 접근 GetBullet() 함수를 새로 만들지 않아도 됌.
		}
	}

	~Police()
	{
		delete[] pistol;
	}
};

int main(void)
{
	Police pman1(5, 3);
	Police pman3(pman1);
	pman3 = pman1;
	
	return 0;
}