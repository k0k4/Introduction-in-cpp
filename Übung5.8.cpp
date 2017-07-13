// Übung5.8.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void error(string s)
{
	throw runtime_error(s);
}

int addierer(vector<int> zahlen, int grenze)
// addiert Zahlen aus vector auf beginnend mit der ersten zahl bis zur Grenze
// Vorbedingung: grenze ist nicht größer als vector size
{
	int sum = 0;
	
	if (grenze  > zahlen.size())
	{
		error("Grenze zu hoch, vector nicht gross genug");
		return -1;
	}
		
	for (int i = 0; i < grenze; i++)
	{
		sum += zahlen[i];
	}

	return sum;
}



int main()
{
    
	double eingabe;
	vector<double>zahlen;
	vector<double>diferenzen;

	try
	{
		
		while (cin >> eingabe)
		{
			if (eingabe == 0)
				break;
			
			zahlen.push_back(eingabe);
		}
		
		for (int i = 0; i < zahlen.size()-1; i++)
		{
			cout << zahlen[i] - zahlen[i + 1] << "\n";
		}
		
		return 0;
		
	}

	catch (exception& e)
	{
		cout << "Error:" << e.what();
	}
	
	return 0;
}

