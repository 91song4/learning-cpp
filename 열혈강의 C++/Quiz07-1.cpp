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
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
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
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
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
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
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
	// 문제 1.
	{
		HybridWaterCar hw(10, 20, 30);
		hw.ShowCurrentGauge();
	}

	// 문제 2.
	{
		MyFriendDetailInfo ex1("song", 31, "취...취...취직...취직... 여기는 오메가 .. 여기는 오메가 들리는가.. 취칮ㄱ...", "010-1234-5678");
		ex1.ShowMyFriendDetailInfo();
	}

	return 0;
}