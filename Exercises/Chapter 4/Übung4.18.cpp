// übung4.18.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
using namespace std;


void error(string s)
{
	throw runtime_error(s);
}


int main()
{
	double  a,  b,  c, det = 0, x1 , x2;

	try
	{
		while (cin >> a >> b >> c) {

			if (a != 1 && a != -1) {
				a = a / a;
				b = b / a;
				c = c / a;
			}



			if (a < 0) {
				a *= (-1);
				b *= (-1);
				c *= (-1);
			}

			det = ((b*b) / 4) - c;

			if (det < 0) {
				error("Keine echte Wurzel");
				continue;
			}

			else {
				x1 = ((b / 2)*(-1)) + sqrt(det);
				x2 = ((b / 2)*(-1)) - sqrt(det);
			}

			cout << "X1 = " << x1 << "\n" << "X2 = " << x2 << "\n";

		}
		return 0;
	}
	
	catch (exception& e)
	{
		cout << "Fehler: " << e.what() << "\n";
		return 1;
	}
}

