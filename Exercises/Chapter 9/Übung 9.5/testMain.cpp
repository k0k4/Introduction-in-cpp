#include "testbiblio.h"

using namespace testbib;

int main()
{
	
	isbn is(12, 13, 14, 'g');
	date dd(14, 10, 1920);
	Book buch(is, "Last Kingdom", "Bernard Cornwell", dd, Book::Roman);


	isbn is_2(11, 12, 13, '2');
	date dd_2(22, 6, 2001);
	Book buch_2(is_2, "Das brennende land", "Bernarnd Cornwell", dd_2, Book::Roman);
	
	isbn is_3(201, 123, 134, '9');
	date dd_3(8, 9, 2002);
	Book buch_3(is_3, "Pipi Langstrumpf", "Astrid Lintgreen", dd_3, Book::Kinder);

	isbn is_4(56, 852, 456, 'z');
	date dd_4(26, 8, 2017);
	Book buch_4(is_4, "Psychooo", "Psycho Magazin", dd_4, Book::Zeitschrift);

	cout << buch << buch_2 << buch_3 << buch_4;
	
	Patron mem_1("Adolf Hitler", 33425, 12);
	Patron mem_2("Albert Einstein", 00234, 0);
	Patron mem_3("Hans Oppenheimer", 00123, 0);

	Libary myLib;

	myLib.new_book(buch);
	myLib.new_book(buch_2);
	myLib.new_book(buch_3);
	myLib.new_book(buch_4);

	myLib.new_patron(mem_1);
	myLib.new_patron(mem_2);
	myLib.new_patron(mem_3);
	
	Patron no_mem("ez pz", 1337, 0);

	myLib.give_book(buch, no_mem);
	
	

	char cc; cin >> cc;

}