#include <iostream>

using namespace std;

int strcmp(const char* s1, const char* s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else if (*s1 < *s2)
			return -1;
		else
			return 1;
	}

	if (*s1 == 0 && *s2 != 0)
		return -1;
	else if (*s1 != 0 && *s2 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	char s1[] = "abeta";
	char s2[] = "alpha";

	int r = strcmp(s1, s2);
	cout << r;

	char cc; cin >> cc;
}