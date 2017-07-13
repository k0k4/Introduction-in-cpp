// Übung4.8.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

int eingabeZuInt(string eingabe) {
	if (eingabe == "shore")
		return 1;
	else if (eingabe == "stein")
		return 2;
	else if (eingabe == "papier")
		return 3;
}

int siegerf(int player, int comp) {														// 1 = Shore, 2 = Stein, 3 = Papier
	if (player == comp)
		return 0;
	else if (player == 1 && comp == 2)
		return 2;
	else if (player == 1 && comp == 3)
		return 1;
	else if (player == 2 && comp == 1)
		return 1;
	else if (player == 2 && comp == 3)
		return 2;
	else if (player == 3 && comp == 1)
		return 2;
	else if (player == 3 && comp == 2)
		return 1;
}

string eingabeZuString(int eingabe) {

	if (eingabe == 1)
		return "Shore";
	else if (eingabe == 2)
		return "Stein";
	else if (eingabe == 3)
		return "Papier";
}



int main()
{
	
	vector<int>zahlenSp;
	int eingabe,temp;
	string playerTurn;

	cout << "Shore , Stein, Papier....\n initialiesieren der Computer Zuege\n";

	for (int i = 0; i < 10; i++) {			// initialisiere die Computerzüge
		cin >> eingabe;
		zahlenSp.push_back(eingabe);
	}

	for (int i = 0; i < 10; i++) {
		cout << "Ihr Zug >> ";
		cin >> playerTurn;					// Auswertung beider Züge

		cout << "Computer Zug >> " << eingabeZuString(zahlenSp[i]) << "\n";
		
		

		
		if (siegerf(eingabeZuInt(playerTurn), zahlenSp[i]) == 0)
			cout << "Unentschieden! \n";
		else if (siegerf(eingabeZuInt(playerTurn), zahlenSp[i]) == 1)
			cout << "Sie haben Gewonnen!\n";
		else if (siegerf(eingabeZuInt(playerTurn), zahlenSp[i]) == 2)
			cout << "Computer Gewinnt!\n"; 
		
	}


	
	return 0;
}

