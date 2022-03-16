#ifndef __AccountArray_h__
#define __AccountArray_h__
#include"BankingCommonDecl.h"
#include"Account.h"
class AccountArray
{
private:
	Account** arr;
	int arrlen;

	AccountArray(const AccountArray& arr) {}
	AccountArray& operator=(const AccountArray& arr) {}

public:
	int GetArrLen() const;

public:
	Account*& operator[](int idx);
	Account*& operator[](int idx) const;
	
public:
	AccountArray(int len);
	~AccountArray();
};

#endif