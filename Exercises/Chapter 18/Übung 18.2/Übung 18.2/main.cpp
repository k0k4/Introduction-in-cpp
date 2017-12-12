#include <iostream>

using namespace std;

char* findx(const char* s, const char* x)
{
	bool isEqual = true;
	int cs = 0;
	while (*s)
	{
		if (*s == *x)
		{	
			
			//cout << "value s =" << *s << " value x = " << *x << "\n";
			while (*s != 0 && *x != 0)
			{
				if (*s != *x)
				{
					isEqual = false;
					break;
				}

				else
				{
					x++;
					s++;
					cs++;
		
				}
			}

			s -= cs;
			x -= cs;
			cs = 0;

			if (isEqual)
				return (char*) s;
			else
			{
				s++;
				isEqual = true;
			}
				
		}
		else
			s++;
	}
}

int main()
{
	char tests[] = "this is a test to check if the function works";
	char testx[] = "test";

	char* p = findx(tests, testx);

	cout << p[0];

	char cc; cin >> cc;
}