#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Calculator
{
private:
	unsigned short m_CoutAdd;
	unsigned short m_CoutMin;
	unsigned short m_CoutDiv;
	unsigned short m_CoutMul;

public:
	void Init() { m_CoutAdd = 0, m_CoutMin = 0, m_CoutDiv = 0, m_CoutMul = 0; }
	double Add(double _a, double _b);
	double Min(double _a, double _b);
	double Div(double _a, double _b);
	double Mul(double _a, double _b);
	void ShowOpCount();
};

class Printer
{
private:
	char m_ch[20];
public:
	char SetString(const char* _string);
	void ShowString();
};

int main(void)
{
	// ¹®Á¦ 1.
	{
		Calculator cal;
		cal.Init();
		cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
		cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
		cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
		cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
		cal.ShowOpCount();
	}

	// ¹®Á¦ 2.
	{
		Printer pnt;
		pnt.SetString("Hello world!");
		pnt.ShowString();

		pnt.SetString("I love C++");
		pnt.ShowString();
	}
	return 0;
}

double Calculator::Add(double _a, double _b)
{
	++m_CoutAdd;
	return _a + _b;
}

double Calculator::Min(double _a, double _b)
{
	++m_CoutMin;
	return _a - _b;
}

double Calculator::Div(double _a, double _b)
{
	++m_CoutDiv;
	return _a / _b;
}

double Calculator::Mul(double _a, double _b)
{
	++m_CoutMul;
	return _a * _b;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << m_CoutAdd<<" ";
	cout << "»¬¼À: " << m_CoutMin<<" ";
	cout << "°ö¼À: " << m_CoutMul <<" ";
	cout << "³ª´°¼À: " << m_CoutDiv <<endl;
}

char Printer::SetString(const char* _string)
{
	strcpy_s(m_ch, _string);
	return 0;
}

void Printer::ShowString()
{
	cout << m_ch << endl;
}