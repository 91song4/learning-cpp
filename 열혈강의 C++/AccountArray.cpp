#include "AccountArray.h"

int AccountArray::GetArrLen() const
{
	return arrlen;
}

Account*& AccountArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

Account*& AccountArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

AccountArray::AccountArray(int len)
	: arrlen(len)
{
	arr = new Account * [len];
}

AccountArray::~AccountArray()
{
	delete[] arr;
}
