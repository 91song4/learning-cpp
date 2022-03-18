#include"ArrayTemplate.h"
#include"PointTemplate.h"
//#include"PointTwo.h"

int main(void)
{
	{

		///*** int형 정수 저장 ***/
		//BoundCheckArray<int> iarr(5);
		//for (int i = 0; i < 5; ++i)
		//	iarr[i] = (i + 1) * 11;
		//for (int i = 0; i < 5; ++i)
		//	cout << iarr[i] << endl;

		///*** Point 객체 저장 ***/
		//BoundCheckArray<Point> oarr(3);
		//oarr[0] = Point(3, 4);
		//oarr[1] = Point(5, 6);
		//oarr[2] = Point(7, 8);
		//for (int i = 0; i < oarr.GetArrLen(); ++i)
		//	cout << oarr[i] << endl;

		///*** Point 객체의 주소 값 저장 ***/
		//BoundCheckArray<Point*> parr(3);
		//parr[0] = new Point(3, 4);
		//parr[1] = new Point(5, 6);
		//parr[2] = new Point(7, 8);
		//for (int i = 0; i < parr.GetArrLen(); ++i)
		//	cout << *(parr[i]) << endl;
		//delete parr[0];
		//delete parr[1];
		//delete parr[2];
	}

	BoundCheckArray<Point<int>> oarr1(3);
	oarr1[0] = Point<int>(3, 4);
	oarr1[1] = Point<int>(5, 6);
	oarr1[2] = Point<int>(7, 8);

	for (int i = 0; i < oarr1.GetArrLen(); ++i)
		oarr1[i].ShowPosition();

	BoundCheckArray<Point<double>> oarr2(3);
	oarr2[0] = Point<double>(3.14, 4.31);
	oarr2[1] = Point<double>(5.09, 6.07);
	oarr2[2] = Point<double>(7.82, 8.54);

	for (int i = 0; i < oarr2.GetArrLen(); ++i)
		oarr2[i].ShowPosition();

	BoundCheckArray<Point<int>*> oparr(3);
	oparr[0] = new Point<int>(11, 12);
	oparr[1] = new Point<int>(13, 14);
	oparr[2] = new Point<int>(15, 16);

	for (int i = 0; i < oparr.GetArrLen(); ++i)
		oparr[i]->ShowPosition();

	delete oparr[0];
	delete oparr[1];
	delete oparr[2];
	return 0;
}