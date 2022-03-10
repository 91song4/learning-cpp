#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// ���� 1. �����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����Ͽ���.
//	-> ���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
//	-> ���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�

// ���� 2. �ռ� �Ұ��� ���� RefSwap.cpp�� SwapByRef2 �Լ��� ������ ���·� ȣ���ϸ� ������ ������ �߻��Ѵ�.
// SwapByRef2(23,45);
// ������ ������ �߻��ϴ� ������ �������� �����غ���.
// ����� ������� �����ڼ����� ���� ����.

// ���� 3. ������ ���ÿ� �ռ� ���� ���� �ڵ带 ����.

void Increase(int& _num)
{
	++_num;
}

void PlusMinus(int& _num)
{
	_num *= -1;
}

void SwapPointer(int*& _ptr1, int*& _ptr2)
{
	int* temp = _ptr1;
	_ptr1 = _ptr2;
	_ptr2 = temp;
}

int main(void)
{
	// ���� 1.
	{
		int num = 2;

		Increase(num);
		cout << num << endl;

		PlusMinus(num);
		cout << num << endl;
	}

	//���� 3.
	{
		int num1 = 5;
		int* ptr1 = &num1;

		int num2 = 10;
		int* ptr2 = &num2;

		SwapPointer(ptr1, ptr2);
		cout << *ptr1 << endl;
		cout << *ptr2 << endl;
	}
	return 0;
}