// Übung6.10.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void error(string s)
{
	throw runtime_error(s);
}

int faculty(int value)
{
	int temp = 1;
	
	if (value == 0 || value == 1)
		return 1;

	for (int i = 2; i <= value; i++)
		temp *= i;

	return temp;
}



int permutation(int value, int value2)
{
	int limit = value;
	int temp = (value - value2) + 1;

	if (temp == 0 || temp == 1)
		return 1;

	for (int i = temp + 1; i <= limit; i++)
		temp *= i;

	return temp;
}

int kombination(int a, int b)
{
	int ergebnis;

	ergebnis = permutation(a, b) / faculty(b);

	return ergebnis;
}



void lesen()
{
	int a, b;
	string interaktion;

	
	cout << "Geben sie 2 Zahlen ein: ";
	cin >> a >> b;

	cout << "Wollen sie eine Permutation oder Kombination ausfuehren?(per/kom) \n";
	cin >> interaktion;

	if (interaktion == "per")
	{
		cout << "Anzhal der permutationen = " << permutation(a, b) << "\n";
	}

	else if (interaktion == "kom")
	{
		cout << "Anzahl der kombinationen = " << kombination(a, b) << "\n";
	}

	else
		cout << "Error: kein bekannter befehl";

	
}

int main()
{
	try
	{
		lesen();
	}

	catch (exception& e)
	{
		cout << "Error: " << e.what() << "\n";
	}
	
	return 0;
}

