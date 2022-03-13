#include<iostream>
using std::cout;
using std::endl;

class First
{
public:
	virtual void Myfunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
	virtual void Myfunc() { cout << "SecondFunc" << endl; }	
	// �ֻ��� �θ�Ŭ�������� virtual Myfunc()�� virtualŰ���尡 �پ �����Լ��� �ȴ�. virtual Ű���带 ����� ������ ��������� �����ִ°��� ����.
};

class Third : public Second
{
public:
	virtual void Myfunc() { cout << "ThirdFunc" << endl; }
	// �ֻ��� �θ�Ŭ�������� virtual Myfunc()�� virtualŰ���尡 �پ �����Լ��� �ȴ�. virtual Ű���带 ����� ������ ��������� �����ִ°��� ����.
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

// �Լ��� �����Լ�(virtual)�� ����Ǹ�, �ش� �Լ�ȣ�� ��, �������� �ڷ����� ������� ȣ������ �������� �ʰ�,
// ������ ������ ������ ����Ű�� ��ü�� �����Ͽ� ȣ���� ����� �����Ѵ�.