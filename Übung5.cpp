// übung5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void error(string s) {
	throw runtime_error(s);
}

double ctok(double c)
{
	if (c < -275.15)
		error(" eingegebener Wert ist zu niedrig");

	double k = c + 275.15;
	return k;
}

double ktok(double k)
{
	if (k > 275.15 || k <= 0)
		error(" eingegebener Wert ist zu niedrig oder zu Gross");

	double c = k - 275.15;
	return c;
}

int main()
{
	try {
		
		double eingabe;
		char einheit;

		cin >> eingabe >> einheit;

		if (einheit != 'c' && einheit != 'k')
			error("keine bekannte Einheit");

		if (einheit == 'c')
		{
			double k = ctok(eingabe);
			cout << k << "\n";
		}

		else if (einheit == 'k')
		{
			double c = ktok(eingabe);
			cout << c << "\n";
		}

		
		
		return 0;
	}

	catch (exception& e) {
		cout << "Fehler:" << e.what() << "\n";
		return 1;
	}

	catch (...) {
		cout << "Hoppla: unbekannte Ausnahme!\n";
		return 2;
	}
   
}

