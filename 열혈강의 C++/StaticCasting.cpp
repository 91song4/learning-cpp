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
	Truck* ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->ShowTruckState();
	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2); // ��ȯ�� ��Ű���� ������ ����.
	ptruck2->ShowTruckState();
	cout << endl;
	// static_cast<����Ŭ������>(����Ŭ������)
	// ���� Ŭ������ ������ �� ������ �����͸� ���� Ŭ������ ������ �� ������ �����ͷ� ��ȯ.

	return 0;
}