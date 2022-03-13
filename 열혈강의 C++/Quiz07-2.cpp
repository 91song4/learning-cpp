#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Rectangle	// ���簢��
{
private:
	int base;
	int altitude;

public:
	void ShowAreaInfo()
	{
		cout << "����: " << base * altitude << endl;
	}

public:
	Rectangle(int _base, int _altitude)
		: base(_base)
		, altitude(_altitude)
	{}
};

class Square : public Rectangle	// ���簢��
{
public:
	Square(int _side)
		: Rectangle(_side, _side)
	{}
};

class Book
{
private:
	char* title;	// å�� ����
	char* isbn;		// ����ǥ�ص�����ȣ
	int price;		// å�� ����

public:
	void ShowBookInfo()
	{
		cout << "title: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "price: " << price << endl;
	}

public:
	Book(const char* _title, const char* _isbn, int _price)
		: title(new char[strlen(_title) + 1])
		, isbn(new char[strlen(_isbn) + 1])
		, price(_price)
	{
		//title = new char[strlen(_title) + 1];
		//isbn = new char[strlen(_isbn) + 1];
		strcpy_s(title, strlen(_title) + 1, _title);
		strcpy_s(isbn, strlen(_isbn) + 1, _isbn);
	}

	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;	// ���Ȱ��� Ű

public:
	void showEBookInfo()
	{
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}

public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
		: Book(_title, _isbn, _price)
		, DRMKey(new char[strlen(_DRMKey) + 1])
	{
		//DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy_s(DRMKey, strlen(_DRMKey) + 1, _DRMKey);
	}

	~EBook()
	{
		delete[] DRMKey;
	}
};

int main(void)
{
	// ���� 1.
	{
		Rectangle rec(4, 3);
		rec.ShowAreaInfo();

		Square sqr(7);
		sqr.ShowAreaInfo();
	}

	// ���� 2.
	{
		Book book("���� C++", "555-12345-890-0", 20000);
		book.ShowBookInfo();
		cout << endl;
		EBook ebook("���� C++ ebook", "555-12345-890-0", 10000, "fdx9w0i8kiw");
		ebook.showEBookInfo();

	}

	return 0;
}