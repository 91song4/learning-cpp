#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class AAA
{
public:
	void ShowYou() { cout << "AAA exception!" << endl; }
};

class BBB : public AAA
{
public:
	void ShowYou() { cout << "BBB exception!" << endl; }
};

class CCC : public BBB
{
public:
	void ShowYou() { cout << "CCC exception!" << endl; }
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();
}

int main(void)
{
	try
	{
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	// 예외가 발생하면, 해당 예외 데이터를 전달받을 수 있는 catch 블록을 위에서 아래로 찾아 내려간다.
	// 그리고 적절한 catch 블록을 찾게 되면, 해당 catch 블록이 실행되면서 예외의 처리는 완료가 된다.
	// 예외 클래스가 상속관계로 묶여있다. A<-B<-C 
	catch (AAA& expn) // BBB클래스도 CCC클래스도 AAA클래스의 일종이다.
	{
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB& expn)
	{
		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (CCC& expn)
	{
		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}

	// 제대로 작동하려면 이렇게 작성해야 한다.
	/*
	catch (CCC& expn)
	{
		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB& expn)
	{
		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (AAA& expn) // BBB클래스도 CCC클래스도 AAA클래스의 일종이다.
	{
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	*/
	return 0;
}