#include <iostream>
#include <string>

using namespace std;

void replace_punct()
{
	char ch;
	while (cin >> ch)
	{
		switch (ch)
		{
		case '-': case '.': case ',': case '!': case '?':
			cout << ' ';
			break;
		default:
			cout << ch;
			break;
		}
			
	}
}

int main()
{
	replace_punct();
}