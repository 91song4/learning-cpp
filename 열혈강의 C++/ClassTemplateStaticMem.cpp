#include<iostream>	
using std::cout;
using std::endl;

template<class T>
class SimpleStaticMem
{
private:
	static T mem;

public:
	void AddMem(T num) { mem += num; }
	void ShowMem() { cout << mem << endl; }
};

template<class T>
T SimpleStaticMem<T>::mem = 0;

int main(void)
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);
	obj2.AddMem(3);
	obj1.ShowMem();

	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);
	obj4.ShowMem();
	return 0;
}