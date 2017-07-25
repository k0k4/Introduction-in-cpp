#include <iostream>

using namespace std;

int main()
{
	int birth_year = 1991;
	double d = 1234567.89;

	cout << showbase << "Dez: " << birth_year << '\t' << "Oct: " << oct << birth_year << '\t' << "Hex: " << hex << birth_year << dec << '\n';
	cout << 25 << '\n';

	cout << d << '\n' << fixed << d << '\n' << scientific << d ;
	

	char cc; cin >> cc;
}