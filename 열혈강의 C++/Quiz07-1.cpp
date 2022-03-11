#include<iostream>
using std::cout;
using std::endl;

class Car
{
private:
	int gasolineGauge;

public:
	int GetGasGauge() const
	{
		return gasolineGauge;
	}

public:
	Car(int gas)
		: gasolineGauge(gas)
	{}
};

class HybridCar : public Car
{
private:
	int electricGauge;

public:
	int GetElecGauge() const
	{
		return electricGauge;
	}

public:
	HybridCar(int gas, int elect)
		: Car(gas)
		, electricGauge(elect)
	{}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}

public:
	HybridWaterCar(int gas, int elect, int water)
		: HybridCar(gas, elect)
		, waterGauge(water)
	{}
};

class MyFriendInfo
{
private:
	char* name;
	int age;

public:
	void ShowMyFriendInfo()
	{
		cout << "ÀÌ¸§: " << name << endl;
		cout << "³ªÀÌ: " << age << endl;
	}

public:
	MyFriendInfo(const char* _name, int _age)
		: age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}

	~MyFriendInfo()
	{
		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;

public:
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "ÁÖ¼Ò: " << addr << endl;
		cout << "ÀüÈ­: " << phone << endl << endl;
	}

public:
	MyFriendDetailInfo(const char* _name, int _age, const char* _addr, const char* _phone)
		: MyFriendInfo(_name, _age)
	{
		addr = new char[strlen(_addr) + 1];
		phone= new char[strlen(_phone) + 1];
		strcpy_s(addr, strlen(_addr) + 1, _addr);
		strcpy_s(phone, strlen(_phone) + 1, _phone);
	}

	~MyFriendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
	}
};

int main(void)
{
	// ¹®Á¦ 1.
	{
		HybridWaterCar hw(10, 20, 30);
		hw.ShowCurrentGauge();
	}

	// ¹®Á¦ 2.
	{
		MyFriendDetailInfo ex1("song", 31, "Ãë...Ãë...ÃëÁ÷...ÃëÁ÷... ¿©±â´Â ¿À¸Þ°¡ .. ¿©±â´Â ¿À¸Þ°¡ µé¸®´Â°¡.. Ãë¯¤¡...", "010-1234-5678");
		ex1.ShowMyFriendDetailInfo();
	}

	return 0;
}