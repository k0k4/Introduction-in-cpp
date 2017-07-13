// Übung6.4.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

bool isKonjuntion(string s)
// Überprüft ob wort eine konjunktion  ist
{
	if (s == "und")
		return true;
	else if (s == "aber")
		return true;
	else if (s == "oder")
		return true;
	else
		return false;
}

bool isSubstantiv(string s)
// Überprüft ob wort ein Substantiv ist
{
	string wort;

	if (s == "der" || s == "die" || s == "das")
	{
		cin >> wort;
		if (wort == "voegel")
			return true;
		else if (wort == "fische")
			return true;
		else if (wort == "computer")
			return true;
		else
			false;
	}
	
	
	else
	{
		if (s == "voegel")
			return true;
		else if (s == "fische")
			return true;
		else if (s == "computer")
			return true;
		else
			false;
	}
	
}

bool isVerb(string s)
// Überprüft ob wort ein Verb ist
{
	
		if (s == "rechnen")
			return true;
		else if (s == "fliegen")
			return true;
		else if (s == "schwimmen")
			return true;
		else
			return false;
	
	
}

bool satzKorrekt()
//Überprüft ganzen satz
{
	string wort;
	cin >> wort;

	if (isSubstantiv(wort))				// Prüfe ob sub wenn korrekt fahre fort, wenn nicht satz falsch
	{
		cin >> wort;
		if (isVerb(wort))			//prüfe ob verb, wenn ja fahre fort, wenn icht satz falsch
		{
			cin >> wort;

			if (wort == ".")		//prüfe ob satz korrekt mit "." beendet wurde oder ob eine konjunktion folgt, wenn konjunktion folgt  wiederhole, wenn beides nicht zu trifft kein satz
				return true;
			else if (isKonjuntion(wort))
				return satzKorrekt();
			else
				false;

		}

		else
			return false;
	}

	else
		return false;
	
}

int main()
{
	bool istKorrekt;

	while (cin)
	{
		istKorrekt = satzKorrekt();

		if (istKorrekt)
			cout << "Der Satz ist Korrekt!\n";
		else
			cout << "Der Satz ist nicht Korrekt!\n";
	}
		
	
	cout << "fertig";
	return 0;
}

