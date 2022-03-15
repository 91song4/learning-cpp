#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Book
{
private:
	char* title;	// 책의 제목
	char* isbn;		// 국제표준도서번호
	int price;		// 책의 정가

public:
	void ShowBookInfo()
	{
		cout << "title: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "price: " << price << endl;
	}

public:
	Book& operator=(const Book& copy)
	{
		delete[] title;
		delete[] isbn;
		
		title = new char[strlen(copy.title) + 1];
		strcpy_s(title, strlen(copy.title) + 1, copy.title);

		isbn = new char[strlen(copy.isbn) + 1];
		strcpy_s(isbn, strlen(copy.isbn) + 1, copy.isbn);
		price = copy.price;
		return *this;
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

	Book(Book& copy)
		: price(copy.price)
		, title(new char[strlen(copy.title) + 1])
		, isbn(new char[strlen(copy.isbn) + 1])
	{
		strcpy_s(title, strlen(copy.title) + 1, copy.title);
		strcpy_s(isbn, strlen(copy.isbn) + 1, copy.isbn);
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
	char* DRMKey;	// 보안관련 키

public:
	void showEBookInfo()
	{
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}

public:
	EBook& operator=(const EBook& copy)
	{
		Book::operator=(copy);
		delete[] DRMKey;
		DRMKey = new char[strlen(copy.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(copy.DRMKey) + 1, copy.DRMKey);
		return *this;
	}

public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
		: Book(_title, _isbn, _price)
		, DRMKey(new char[strlen(_DRMKey) + 1])
	{
		//DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy_s(DRMKey, strlen(_DRMKey) + 1, _DRMKey);
	}

	EBook(EBook& copy)
		: Book(copy)
		, DRMKey(new char[strlen(copy.DRMKey) + 1])
	{
		strcpy_s(DRMKey, strlen(copy.DRMKey) + 1, copy.DRMKey);
	}

	~EBook()
	{
		delete[] DRMKey;
	}
};

int main(void)
{
	Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2("C++이 좋아", "222-54321-170-0", 30000);
	book1.ShowBookInfo();
	book1 = book2;
	book1.ShowBookInfo();
	Book book3(book1);
	book3.ShowBookInfo();
	cout << endl;
	EBook ebook1("좋은 C++ ebook", "555-12345-890-0", 10000, "fdx9w0i8kiw");
	EBook ebook2("C++이 좋아 ebook", "222-54321-170-0", 20000, "f39ckm23wvd");
	ebook1.showEBookInfo();
	ebook1 = ebook2;
	ebook1.showEBookInfo();
	EBook ebook3(ebook1);
	ebook3.showEBookInfo();
	return 0;
}