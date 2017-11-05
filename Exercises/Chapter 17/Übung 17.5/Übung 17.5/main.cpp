#include <iostream>

using namespace std;

char* findx(const char* s, const char* x)
{
	
	int i = 0, si = 0, xi = 0;
	char* xpos = 0;
	bool equal = true;
	while (s[i] != 0)
	{
		if (s[i] == x[0])
		{
			si = i;
			while (s[si] != 0 && x[xi] != 0)
			{
				if (s[si] != x[xi])
				{
					equal = false;
					break;
				}
					
				si++;
				xi++;
			}

			if (equal)
				return (char *) &s[i];
			else
			{
				xi = 0;
				equal = true;
			}
			
		}
		i++;

	}
}

int main()
{
	const char s[] = "I am the sectence to check if somethin equal is in it";
	const char x[] = "check";

	char* result = findx(s, x);

	cout << result[4] << "\n";

	char cc; cin >> cc;
}