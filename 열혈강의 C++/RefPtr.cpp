#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;
	cout << pref << endl;
	cout << **dpref << endl;
	cout << *dpref << endl;
	cout << dpref << endl;
	return 0;
}