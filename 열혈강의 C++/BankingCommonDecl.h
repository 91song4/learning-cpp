#ifndef __BankingCommonDecl_h__
#define __BankingCommonDecl_h__

#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

namespace RATING
{
	enum { A = 1, B, C };
}

#endif