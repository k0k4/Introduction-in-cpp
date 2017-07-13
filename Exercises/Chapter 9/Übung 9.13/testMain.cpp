#include "Numbers.h"

using namespace rational_lib;

int main()
{
	Rational a(1, 2);
	Rational b(3, 2);
	Rational c(5, 3);

	cout << a << " + " << b << " = " << a + b << "\n";
	cout << a << " + " << c << " = " << a + c << "\n";
	cout << a << " - " << b << " = " << a - b << "\n";
	cout << a << " - " << c << " = " << a - c << "\n";
	cout << a << " / " << b << " = " << a / b << "\n";
	cout << a << " / " << c << " = " << a / c << "\n";
	cout << a << " * " << b << " = " << a * b << "\n";
	cout << a << " * " << c << " = " << a * c << "\n";
	
	double d = rat_to_double(a);

	cout << a << " in dezimal = " << d << "\n";

	char cc; cin >> cc;
}