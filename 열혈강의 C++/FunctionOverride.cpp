#include<iostream>
using std::cout;
using std::endl;

class First
{
public:
	void Myfunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
	void Myfunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second
{
public:
	void Myfunc() { cout << "ThirdFunc" << endl; }
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->Myfunc();
	sptr->Myfunc();
	tptr->Myfunc();
	delete tptr;
	return 0;
}