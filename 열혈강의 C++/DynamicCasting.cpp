#include<iostream>
using std::cout;
using std::endl;

class Car
{
private:
	int fuelGauge;

public:
	void ShowCarState() { cout << "�ܿ� ���ᷮ: " << fuelGauge << endl; }

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
		cout << "ȭ���� ����: " << freightWeight << endl;
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

	// dynamic_cast<����Ŭ������>(����Ŭ������)
	// ��Ӱ��迡 �ִ� ���� Ŭ������ ������ �� ������ �����͸� ���� Ŭ������ ������ �� ������ �����ͷ� �� ��ȯ
	return 0;
}