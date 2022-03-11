#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void Counter()
{
	static int cnt;
	++cnt;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; ++i)
		Counter();
	return 0;
}