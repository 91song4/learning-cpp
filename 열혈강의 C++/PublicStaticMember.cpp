#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class SoSimple
{
public:
	static int simObjCnt;

public:
	SoSimple()
	{
		//simObjCnt = 0;
		++simObjCnt;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;

int main(void)
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;	// 객체가 생성되지 않았지만 static 변수에 접근
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;		// 객체를 통해서도 static 변수에 접근
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
	return 0;
}

// 클래스 변수는 private 에 선언되면 해당 클래스의 객체들만 접근이 가능
// 클래스 변수는 public에 선언되면 해당 클래스 이름 또는 객체의 이름을 통해서 어디서든 접근이 가능
// 23행을 통해 static 변수는 객체 내에 존재하지 않음을 알 수 있다