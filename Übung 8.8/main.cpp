#include <iostream>

using namespace std;

int randStartwert = 3;

int rand_int()
{
	int rand_zahl = (137*randStartwert + 99991) % 65536;
	randStartwert = rand_zahl;

	return rand_zahl;
}

int rand_in_range(int a, int b)
{
	int diff = b - a;

	return a + (rand_int() % diff);
}

int main()
{
	
	
	for (int i = 0; i < 100; i++)
	{
		cout << rand_in_range(10,20)  << "\n";
		
	}

	char cc; cin >> cc;
}