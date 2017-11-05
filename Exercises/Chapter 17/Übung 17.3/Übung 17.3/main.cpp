#include <iostream>
#include <string.h>

using namespace std;

void to_lower(char* s)
{
	int i = 0;
	while (s[i] != 0)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			s[i] += 32;
			cout << s[i];
			i++;

		}
		else
		{
			cout << s[i];
			i++;
		}
	
	}
}

int main()
{
	char c[] = "Hello World!";
	char* s = c;

	to_lower(c);

	char cc; cin >> cc;

}