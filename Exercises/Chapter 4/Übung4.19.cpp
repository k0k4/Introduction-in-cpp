// übung4.19.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

int namePosition(vector<string> names, string eingabe) {
	for (int i = 0; i < names.size(); i++) 
		if (names[i] == eingabe)
			return i;
	
}

bool nameSuchen(vector<string> names, string eingabe) {
	bool gefunden = false;

	for (int i = 0; i < names.size(); i++) 
		if (names[i] == eingabe)
			gefunden = true;
	

	return gefunden;
}

int main()
{
	vector<string>names;
	vector<int>age;

	string eingabeN;
	int eingabeI;

	while (cin >> eingabeN >> eingabeI) {
		if (eingabeN == "noname" && eingabeI == 0)
			break;

		else if (nameSuchen(names, eingabeN)) {
			cout << "Name schon vorhanden!\n";
			continue;
		}

		else {
			names.push_back(eingabeN);
			age.push_back(eingabeI);
		}
	}

	cout << "Namen suchen >> ";
	cin >> eingabeN;

	if (nameSuchen(names, eingabeN))
		cout << "Position = " << namePosition(names, eingabeN) << "\n";

	else
		cout << "Person nicht gefunden\n";
	
	return 0;
}

