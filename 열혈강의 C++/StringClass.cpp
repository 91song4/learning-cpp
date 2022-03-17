#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class String
{
private: // variable
	char* arr;

public: // operator
	String operator+(const String& copy)
	{
		String temp(strlen(arr) + strlen(copy.arr) + 1);

		for (int i = 0; i < strlen(arr)+1; ++i)
		{
			temp.arr[i] = arr[i];
			while (0 == arr[i])
			{
				for (int j = 0; j < strlen(copy.arr) + 1; ++j)
				{
					temp.arr[i+j] = copy.arr[j];
				}
				break;
			}
		}
		return temp;
	}

	String& operator=(const char* string)
	{
		arr = new char[strlen(string) + 1];
		strcpy_s(arr, strlen(string) + 1, string);
		return *this;
	}

	String& operator=(const String& copy)
	{
		delete[] arr;
		arr = new char[strlen(copy.arr) + 1];
		strcpy_s(arr, strlen(copy.arr) + 1, copy.arr);

		//arr = new char[strlen(string) + 1];
		//strcpy_s(arr, strlen(string) + 1, string);
		return *this;
	}

	String operator+=(const String& ref)
	{
		String temp(arr);
		delete[] arr;
		arr = new char[strlen(temp.arr) + strlen(ref.arr) + 1];
		strcpy_s(arr, strlen(temp.arr) + strlen(ref.arr) + 1, temp.arr);

		for (int i = 0; i < strlen(temp.arr) + 1; ++i)
		{
			while (0 == arr[i])
			{
				for (int j = 0; j < strlen(ref.arr) + 1; ++j)
				{
					arr[i + j] = ref.arr[j];
				}
				break;
			}
		}
		//* this = *this + ref;	// 이러한 형태의 정의는 간결해 보이고 이해하기도 좋지만, 덧셈의 과정에서 객체가 추가로 생성된다는 단점이 있다.
		return *this;
	}

	bool operator==(const String& ref) const
	{
		if (0 == strcmp(arr, ref.arr))
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& os, const String& ref)
	{
		os << ref.arr;
		return os;
	}

	friend istream& operator>>(istream& is, String& ref)
	{
		char ch[100];
		is >> ch;
		ref = ch;
		return is;
	}

public: // constructor, destructor
	String()
		: arr(NULL)
	{}

	String(const int len)
		: arr(new char[len + 1])
	{}
	
	String(const char* string)
		: arr(new char[strlen(string) + 1])
	{
		strcpy_s(arr, strlen(string) + 1, string);
	}

	String(const String& copy)
		: arr(new char[strlen(copy.arr) + 1])
	{
		strcpy_s(arr, strlen(copy.arr) + 1, copy.arr);
	}

	~String()
	{
		delete[] arr;
	}

};

int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3;
	str3= str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}
