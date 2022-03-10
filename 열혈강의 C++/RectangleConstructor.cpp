#include<iostream>
#include"Point.h"
#include"Rectangle.h"
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();
	return 0;
}