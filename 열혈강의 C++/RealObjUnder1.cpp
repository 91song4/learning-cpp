#include<iostream>
using std::cout;
using std::endl;

class Data
{
private:
	int data;

public:
	void ShowData() { cout << "Data: " << data << endl; }
	void Add(int num) { data += num; }

public:
	Data(int num)
		: data(num)
	{}

};

int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	return 0;
}