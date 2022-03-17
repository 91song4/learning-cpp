#ifndef __String_h__
#define __String_h__
#include"BankingCommonDecl.h"
class String
{
private: // variable
	char* arr;

public: // operator
	String operator+(const String& copy);
	String& operator=(const char* string);
	String& operator=(const String& copy);
	String operator+=(const String& ref);
	bool operator==(const String& ref) const;
	friend ostream& operator<<(ostream& os, const String& ref);
	friend istream& operator>>(istream& is, String& ref);

public: // constructor, destructor
	String();
	String(const int len);
	String(const char* string);
	String(const String& copy);
	~String();
};

#endif