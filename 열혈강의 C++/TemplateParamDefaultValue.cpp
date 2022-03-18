#include<iostream>
using std::cout;
using std::endl;

#include<iostream>
using std::cout;
using std::endl;

template<class T=int, int len=7> // Default Value 지정
class SimpleArray
{
private:
	T arr[len];

public:
	T& operator[] (int idx) { return arr[idx]; }
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
	{
		for (int i = 0; i < len; ++i)
			arr[i] = ref.arr[i];
		return *this;
	}
};

int main(void)
{
	SimpleArray<> arr;	// 템플릿클래스 객체생성시 인자로 아무것도 안주더라도 <>기호로 템플릿임을 명시해야한다.
	for (int i = 0; i < 7; ++i)
		arr[i] = i + 1;
	for (int i = 0; i < 7; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}