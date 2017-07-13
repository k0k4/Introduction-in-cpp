// Übung5.11.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

bool contains(vector<int> speicher, int zahl)
{
	bool con = false;

	for (int i = 0; i <= 3; i++)
		if (speicher[i] == zahl)
			con = true;

	return con;
}


int findBulls(vector<int> spielSpeicher,vector<int> spielerEingabe)
//Ermittle wie viele Bullen der Spieler erraten hat
{
	int bulls = 0;

	for (int i = 0; i <= 3; i++)
		if (spielSpeicher[i] == spielerEingabe[i])
			bulls++;

	return bulls;
}

int findCows(vector<int> spielSpeicher, vector<int> spielerEingabe)
//ermittle wie viele Cows der Spieler erraten hat
{
	int cows = 0;

	for (int i = 0; i <= 3; i++)
	{
		//temp = spielerEingabe[i];
		if (spielSpeicher[i] != spielerEingabe[i])
			if (contains(spielSpeicher, spielerEingabe[i]))
				cows++;
	}
		
		

	return cows;
}



int main()
{
    
	vector<int>spielSpeicher;
	vector<int>spielerEingabe;

	int eingabe,val1,cows,bulls;
	string aktion;
	bool weiter;
	bool falsch = true;

	
	while (falsch)
	{
		// Spiel wird Initialisiert
		weiter = true;
		cout << "Initialisiere das Spiel  \n";
		cin >> eingabe;
		// Zufallszahlen werden generiert
		srand(eingabe);
		val1 = rand() % 10;

		for (int i = 0; i <= 3; i++)
		{
			spielSpeicher.push_back(val1);
			val1 = rand() % 10;
		}
		// Spiel wird gespielt
		while (weiter)
		{
			//Spieler Eingabe
			cout << "Bitte Raten >> \n";

			for (int i = 0; i <= 3; i++)
			{
				cin >> eingabe;
				spielerEingabe.push_back(eingabe);
			}

			// Spiel Ausgabe und Berechnung
			bulls = findBulls(spielSpeicher, spielerEingabe);
			cows = findCows(spielSpeicher, spielerEingabe);
			cout << "Du hast " << bulls << " Bulls und " << cows << "Cows\n";

			if (bulls == 4)
			{
				cout << "Du hast Gewonnen!\n Druecke n zum beenden und beliebige Taste fuer weiter\n";
				cin >> aktion;

				if (aktion == "n")
				{
					weiter = false;
					falsch = false;
				}
					
				else
				{
					weiter = false;
				}
			}

			else
			{
				cout << "Noch einmal :) \n";
				spielerEingabe.clear();
			}




		}


	}

	return 0;
}

