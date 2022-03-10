#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
	int x;
	int y;
};

class Rectangle
{
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "�� ���: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "�� �ϴ�: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main(void)
{
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2, pos1 };
	rec.ShowRecInfo();
	return 0;
}