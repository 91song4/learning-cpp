#include<iostream>
using std::cout;
using std::endl;
using std::bad_cast;

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex :public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{
	SoSimple simObj;
	SoSimple& ref = simObj;

	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);
		comRef.ShowSimpleInfo();
	}
	catch (bad_cast expt)
	{
		cout << expt.what() << endl;
	}
}