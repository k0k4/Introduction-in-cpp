#include <iostream>

using namespace std;

char* _strdup(const char* s)
{
	int size = 0;
	while (*s)
	{
		size++;
		s++;
		
	}
	s -= size;
	char* fs = new char(size);
	
	
	for (int i = 0; i < size; i++)
	{
		*fs = *s;
		fs++;
		s++;
		
	}

	return fs -= size;
}

int main()
{
	char s[] = "bello";
	char* sc = _strdup(s);

	for (int i = 0; i < 5; i++)
		cout << sc[i];


	char cc; cin >> cc;
}