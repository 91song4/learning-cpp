#include<iostream>
using std::cout;
using std::endl;

int main(void)
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num);

	for (int i = 0; i < sizeof(num); ++i)
		cout << static_cast<int>(*(ptr + i)) << endl;

	{
		int num = 72;
		int* ptr = &num;

		int adr = reinterpret_cast<int>(ptr);
		cout << "Adder: " << adr << endl;

		int* rptr = reinterpret_cast<int*>(adr);
		cout << "value: " << *rptr << endl;
	}

	return 0;
}