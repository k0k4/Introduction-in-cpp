#include "testbiblio.h"

namespace testbib {
	//Definitionen der Klasse Book und ihre Hilfsfunktionen
	void error(string s)
	{
		throw runtime_error(s);
	}

	isbn::isbn(int fi, int se, int th, char c)
		: fir(fi), sec(se), thi(th), cc(c) {}

	isbn::isbn()
		: fir(0), sec(0), thi(0), cc('0') {}

	date::date()
		:day(1), month(1), year(1900) {}

	Transaction::Transaction(Book b, Patron p, date d)
		:bo(b), po(p), da(d) {}



	Book& default_book()
	{
		isbn is(0, 0, 0, '0');
		date dd(1, 1, 1950);
		static Book bb(is, "noname", "noname", dd , Book::Kinder);
		return bb;
	}

	bool is_date(int dd, int mm, int yy)
	{
		return (dd < 32 && mm < 13 && yy > 1820);
	}

	Book::Book(isbn is, string ti, string au, date da, Genre ge)
		:isbn_1(is), titel(ti), autor(au), date_1(da), genre_1(ge)
	{
		if (!is_date(da.day, da.month, da.year)) throw invalid();
	}

	Book::Book()
		:isbn_1(default_book().get_isbn()),
		titel(default_book().get_titel()),
		autor(default_book().get_autor()),
		date_1(default_book().get_date())
	{
	}
	
	void Book::borrow_book()
	{
		borrow = true;
	}

	void Book::book_putback()
	{
		borrow = false;
	}

	bool operator==(const Book& a, const Book& b)
	{
		return (a.get_isbn().fir == b.get_isbn().fir && a.get_isbn().sec == b.get_isbn().sec
			&& a.get_isbn().thi == b.get_isbn().thi && a.get_isbn().cc == b.get_isbn().cc);
	}

	bool operator!=(const Book& a, const Book& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Book& b)
	{
		os << "Titel: " << b.get_titel() << "\n"
			<< "Autor: " << b.get_autor() << "\n"
			<< "ISBN: " << b.get_isbn().fir << "-" << b.get_isbn().sec << "-" << b.get_isbn().thi << "-" << b.get_isbn().cc << "\n";

		return os;
	}

	//definition class Patron

	Patron::Patron(string user, int card, double deb)
		:user_name(user), card_num(card), debts(deb)
	{
	}

	Patron::Patron()
		:user_name("no_user",-1,0)
	{
	}

	void Patron::put_debts(double d)
	{
		debts = d;
	}

	bool Patron::has_debts()
	{
		return (debts > 0);
	}

	bool operator==(const Patron& a,const Patron& b)
	{
		
		return a.get_card() == b.get_card();
	}

	// definition class Libary

	void Libary::new_book(Book b)
	{
		lib_col.push_back(b);
	}

	void Libary::new_patron(Patron p)
	{
		lib_member.push_back(p);
	}

	bool Libary::have_book(Book b)
	{
		bool result = false;

		for (int i = 0; i < lib_col.size(); i++)
			if (lib_col[i] == b)
			{
				result = true;
				break;
			}
		
		return result;
	}

	bool Libary::have_member(Patron p)
	{
		bool result = false;

		for (int i = 0; i < lib_member.size(); i++)
			if (lib_member[i] == p)
			{
				result = true;
				break;
			}

		return result;
	}

	void Libary::give_book( Book b, Patron p)
	{
		if (have_book(b) && have_member(p))
			if (p.get_debts() == 0.0)
			{
				date d(7, 5, 2017);
				Transaction t(b, p, d);
				lib_trans.push_back(t);
			}
			else
				cout << "U have to pay your debts feggit! \n";
		else
			cout << "You are no member of us do you MEMBER?=! \n";
	}

	vector<Patron> Libary::pat_with_deb()
	{
		vector<Patron> broke_feggits;
		for (int i = 0; i < lib_member.size(); i++)
			if (lib_member[i].get_debts() > 0)
				broke_feggits.push_back(lib_member[i]);

		return broke_feggits;
	}
}




