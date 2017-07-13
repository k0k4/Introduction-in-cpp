#include <iostream>

using namespace std;

namespace rational_lib
{
	class Rational
	{
	public:
		Rational(int a, int b);
		Rational();

		//Read
		int get_counter() const { return counter; }
		int get_namer() const { return namer; }
		
		//Write
		void set_counter(int a) {
			counter = a;
		}

		void set_namer(int a) {
			namer = a;
		}

	private:
		int counter;
		int namer;
	};

	//Operationen für Rational
	// Operatoren Überladungen
	ostream& operator<<(ostream& os, const Rational& r);
	Rational operator+(const Rational a, const Rational b);
	Rational operator-(const Rational a, const Rational b);
	Rational operator/(const Rational a, const Rational b);
	Rational operator*(const Rational a, const Rational b);
	// Weitere Operationen
	double rat_to_double( Rational r);

}
