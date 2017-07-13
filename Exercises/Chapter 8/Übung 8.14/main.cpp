#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<int> count_string(const vector<string>& vs)
{
	vector<int> count;
	//Zeichenanzahl ermitteln und in vector speichern
	for (int i = 0; i < vs.size(); i++)
	{
		count.push_back(vs[i].length());
	}

	return count;
}

//Gibt länge des längsten string im vector aus
int long_string(const vector<int>& vi)
{
	int max = vi[0];
	//ermittle max
	for (int i = 0; i < vi.size(); i++)
		if (vi[i] > max)
			max = vi[i];

	return max;
}
// gibt die länge des kürzesten string im vector aus
int short_string(const vector<int>& vi)
{
	int min = vi[0];
	//ermittle min
	for (int i = 0; i < vi.size(); i++)
		if (vi[i] < min)
			min = vi[i];

	return min;
}

string alpha_first(vector<string> vs)
{
	sort(vs.begin(), vs.end());

	return vs[0];
}

string alpha_last(vector<string> vs)
{
	sort(vs.begin(), vs.end());

	return vs[vs.size() - 1];
}

void print_ergebnis(const vector<string>& zeichensatz, const vector<int>& laenge)
{
	//Zeichen länge ausgeben
	for (int i = 0; i < zeichensatz.size(); i++)
		cout << zeichensatz[i] << " = " << laenge[i] << " zeichen lang \n";
	//längster string
	int max = long_string(laenge);
	for (int i = 0; i < zeichensatz.size(); i++)
		if (zeichensatz[i].length() == max)
			cout << "Laengster string = " << zeichensatz[i] << "\n";
	//kürzester string
	int min = short_string(laenge);
	for (int i = 0; i < zeichensatz.size(); i++)
		if (zeichensatz[i].length() == min)
			cout << "Kuerzester string = " << zeichensatz[i] << "\n";
	//Alphabetisch erster string
	cout << "Alphabetisch erster string = " << alpha_first(zeichensatz) << "\n";
	//Alphabetisch letzter string
	cout << "Alphabetisch letzter string = " << alpha_last(zeichensatz) << "\n";

}

int main()
{
	vector<string> testS;

	testS.push_back("Salz");
	testS.push_back("Sperma");
	testS.push_back("Kuchen");
	testS.push_back("Elefant");
	testS.push_back("Monitor");
	testS.push_back("Computer");
	testS.push_back("Prozessor");

	vector<int> testI = count_string(testS);
	
	print_ergebnis(testS, testI);
	
	char cc; cin >> cc;
}