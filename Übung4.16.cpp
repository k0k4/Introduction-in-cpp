// Übung4.16.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

int modalwert(vector<int> zahlenreihe) {


	int temp = zahlenreihe[0], count = 0,oldcount = 0, mod = 0;

	for (int i = 0; i < zahlenreihe.size(); i++) {
		
		if (temp != zahlenreihe[i]) {
			if (count > oldcount){
				oldcount = count;
				mod = temp;
			}
				
			temp = zahlenreihe[i];
			count = 1;
		}
			
		else
			count++;

		
	}

	return mod;
	
}

int min(vector<int> zahlenreihe) {

	int min = zahlenreihe[0];

	for (int i = 1; i < zahlenreihe.size(); i++) 
		if (zahlenreihe[i] < min)
			min = zahlenreihe[i];

	return min;
	
}

int max(vector<int> zahlenreihe) {
	int max = zahlenreihe[0];

	for (int i = 1; i < zahlenreihe.size(); i++)
		if (zahlenreihe[i] > max)
			max = zahlenreihe[i];

	return max;
}

int main()
{
	vector<int>eingZahlenreihe;
	int eingabe;

	while (cin >> eingabe) 
		eingZahlenreihe.push_back(eingabe);

	sort(eingZahlenreihe.begin(),eingZahlenreihe.end());

	cout << "Modalwert = " << modalwert(eingZahlenreihe) << "\n" << "Minimum = " << min(eingZahlenreihe) << "\n" << "Maximum = "<< max(eingZahlenreihe) << "\n";
	
	
	return 0;
}

