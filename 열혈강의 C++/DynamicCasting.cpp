#include<iostream>
using std::cout;
using std::endl;

class Car
{
private:
	int fuelGauge;

public:
	void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }

public:
	Car(int fuel)
		: fuelGauge(fuel)
	{}
};

class Truck :public Car
{
private:
	int freightWeight;

public:
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}

public:
	Truck(int fuel, int weight)
		: Car(fuel)
		, freightWeight(weight)
	{}
};

int main(void)
{
	Car* pcar1 = new Truck(80, 200);
	//Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);

	Car* pcar2 = new Car(120);
	//Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);

	Car* pcar3 = new Truck(70,150);
	Car* ptruck3 = dynamic_cast<Car*>(pcar3);

	// dynamic_cast<기초클래스형>(유도클래스형)
	// 상속관계에 있는 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환
	return 0;
}