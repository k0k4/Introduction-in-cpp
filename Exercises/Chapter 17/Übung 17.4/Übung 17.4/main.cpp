#include <iostream>

using namespace std;

char* _strdup(const char* s)
{
	int i = 0, size = 0;
	while (s[i] != 0)
		i++;

	size = i + 1;
	char* free = new char[size];
	for (int j = 0; j < size; j++)
		free[j] = s[j];

	return free;
}

int main()
{
	const char c[] = "Hallo, Welt!";
	char* free = _strdup(c);

	int i = 0;
	while (free[i] != 0)
	{
		cout << free[i];
		i++;
	}
	

	char cc; cin >> cc;
}