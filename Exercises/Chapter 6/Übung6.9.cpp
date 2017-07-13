// Übung6.9.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void error(string s)
{
	throw runtime_error(s);
}

int tooInt(char c)
{
	int einer = c - '0';
	return einer;
}

void ausgabe()
{
	vector<int>zahlen;
	char ch;
	int count = 0;
	while (cin >> ch)
	{
		if (ch == ';')
			break;
		else
		{
			zahlen.push_back(tooInt(ch));
			cout << ch;
			
		}
		
	}

	cout << " ist ";
		
	if (zahlen.size() > 4)
		error("eingabe ist zu gross, bis zu 4 zahlen gueltig");
	
	else if (zahlen.size() == 4)
		cout << zahlen[3] << " Tausender, " << zahlen[2] << " Hunderter, " << zahlen[1] << " Zehner, " << zahlen[0] << " einer";
	else if (zahlen.size() == 3)
		cout << zahlen[2] << " Hunderter, " << zahlen[1] << " Zehner, " << zahlen[0] << " einer";
	else if (zahlen.size() == 2)
		cout << zahlen[1] << " Zehner, " << zahlen[0] << " einer";
	else if (zahlen.size() == 1)
		cout << zahlen[0] << " einer";


}

int main()
{
	try
	{
		ausgabe();
	}
	
	catch (exception& e)
	{
		cout << "Error: " << e.what() << "\n";
	}

	return 0;
}

