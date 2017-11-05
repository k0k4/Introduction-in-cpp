#include <iostream>

using namespace std;

char* in_array()
{
	char* c = new char[120];
	char c_in;
	int i = 0;
	while (cin >> c_in)
	{
		if (c_in != '!')
		{
			c[i] = c_in;
			i++;
		}
			
		else
		{
			c[i] = '!';
			break;
		}
			
	}

	return c;
}

int main()
{
	char* c = in_array();

	char cc; cin >> cc;
}