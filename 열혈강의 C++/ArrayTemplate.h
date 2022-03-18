#ifndef __ArrayTemplate_h__
#define __ArrayTemplate_h__
#include<iostream>
using std::cout;
using std::endl;

template<class T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}
public:
	int GetArrLen() const;

public:
	T& operator[](int idx);
	T& operator[](int idx) const;

public:
	BoundCheckArray(int len);
	~BoundCheckArray();
};

template<class T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template<class T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<class T>
T& BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<class T>
BoundCheckArray<T>::BoundCheckArray(int len)
	: arrlen(len)
{
	arr = new T[len];
}

template<class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}

#endif