#include<string>
#include<iostream>
#include<vector>

using namespace std;

namespace testbib 
{
	// class Book
	
	void error(string s);

	

	struct isbn
	{
		int fir, sec, thi;
		char cc;
	
		isbn(int fi, int se, int th, char c);
		isbn();
	};

	struct date
	{
		int day, month, year;
		date(int dd, int mm, int yy)
			: day(dd), month(mm), year(yy){}
		date();
	};
	
	
	class Book 
	{
	public:
		class invalid{};
		
		enum Genre {
			Roman = 1, Sachbuch, Zeitschrift, Biografie, Kinder
		};

		Book(isbn is, string ti, string au, date da, Genre ge);
		Book();

		//Read
		isbn get_isbn() const  { return isbn_1 ; }
		string get_titel() const { return titel; }
		string get_autor() const { return autor; }
		date get_date() const { return date_1; }
		bool get_bor() const { return borrow; }
		Genre get_genre() const { return genre_1; }

		//Write
		void borrow_book();
		void book_putback();

	private:
		isbn isbn_1;
		string titel;
		string autor;
		date date_1;
		bool borrow;
		Genre genre_1;
	};

	
	bool is_date(int dd, int mm, int yy);

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);
	ostream& operator<<(ostream& os, const Book& b);

	//class Patron

	class Patron
	{
	public:
		Patron(string user, int card, double deb);
		Patron();
		
		//Read
		string get_user() const { return user_name; }
		int get_card() const { return card_num; }
		double get_debts() const { return debts; }
		
		//Write
		void put_debts(double d);
		bool has_debts();
	private:
		string user_name;
		int card_num;
		double debts;
	};

	bool operator==(const Patron& a, const Patron& b);

	//class Libary
	

	struct Transaction
	{
		Book bo;
		Patron po;
		date da;

		Transaction(Book b, Patron p, date d);
	};

	class Libary
	{
	public:
		void new_book(Book b);
		void new_patron(Patron p);
		void give_book(Book b, Patron p);
		bool have_book(Book b);
		bool have_member(Patron p);
		vector<Patron> pat_with_deb();
	
	private:
		vector<Book>lib_col;
		vector<Patron>lib_member;
		vector<Transaction>lib_trans;
	};

	
}