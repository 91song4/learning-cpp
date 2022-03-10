#include<iostream>
#include<ctime>
#include<cstdlib>

using std::cin;
using std::cout;
using std::endl;

void Quiz1()
{
	char ch1[] = "song";
	char ch2[10] = "song";

	int lne = strlen(ch1);
	strcat_s(ch2, "4");
	strcpy_s(ch2, ch1);
	bool tf = strcmp(ch1, ch2);
}

void Quiz2()
{
	srand(time(NULL));
	cout<<rand()%100<<endl;
	cout<<rand()%100<<endl;
	cout<<rand()%100<<endl;
	cout<<rand()%100<<endl;
	cout<<rand()%100<<endl;
	srand;
	time;
}

int main(void)
{
	//Quiz1();
	Quiz2();
	return 0;
}