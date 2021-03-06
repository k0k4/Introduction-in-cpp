// �bung4.15.cpp 
// Return first n prims

#include "stdafx.h"

using namespace std;

// return int if its a prim
bool prim(int eingabe) {
	
	bool isPrim = true;
	
	for (int i = 2; i <= eingabe; i++) {
		if (eingabe % i == 0 && eingabe != i)
			return false;
	}

	return true;
}

int main()
{
	int eingabe, primZahlen = 0, counter = 2;

	cout << ">> ";
	cin >> eingabe;
	
	while (primZahlen < eingabe) {
		if (prim(counter)) {
			primZahlen++;
			cout << counter << "\n";
			counter++;
		}

		else
			counter++;
			
	}

	return 0;
}

