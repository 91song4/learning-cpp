#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct Point
{
	int xpos;
	int ypos;

	void MovePos(int x, int y)			// 점의 좌표이동
	{
		xpos += x;
		ypos += y;
	}

	void AddPoint(const Point& pos)		// 점의 좌표증가
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
	}

	void ShowPosition()					// 현재x, y 좌표정보 출력
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

int main(void)
{
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
}