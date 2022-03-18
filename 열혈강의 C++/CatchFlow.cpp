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
	// ���ܰ� �߻��ϸ�, �ش� ���� �����͸� ���޹��� �� �ִ� catch ����� ������ �Ʒ��� ã�� ��������.
	// �׸��� ������ catch ����� ã�� �Ǹ�, �ش� catch ����� ����Ǹ鼭 ������ ó���� �Ϸᰡ �ȴ�.
	// ���� Ŭ������ ��Ӱ���� �����ִ�. A<-B<-C 
	catch (AAA& expn) // BBBŬ������ CCCŬ������ AAAŬ������ �����̴�.
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

	// ����� �۵��Ϸ��� �̷��� �ۼ��ؾ� �Ѵ�.
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
	catch (AAA& expn) // BBBŬ������ CCCŬ������ AAAŬ������ �����̴�.
	{
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	*/
	return 0;
}