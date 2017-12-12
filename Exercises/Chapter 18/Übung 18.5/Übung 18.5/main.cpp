#include <iostream>
#include <string>

using namespace std;

char* cat_dot(const char* s1, const char* s2)
{
	int size = 0, c1 = 0, c2 = 0;
	
	while (s1[c1])
	{
		size++;
		c1++;
	}
	c1 = 0;
	while (s2[c1])
	{
		size++;
		c1++;
	}

	char* ss = new char[size + 2];
	c1 = 0;

	while (s1[c1])
	{
		ss[c2] = s1[c1];
		c1++;
		c2++;
	}
	ss[c2++] = '.';
	c1 = 0;
	while (s2[c1])
	{
		ss[c2] = s2[c1];
		c1++;
		c2++;
	}
	ss[c2] = 0;
	return ss;

}

int main()
{
	char s1[] = "peter";
	char s2[] = "wurst";

	char* p = cat_dot(s1, s2);
	
	int i = 0;
	while (p[i])
		cout << p[i++];

	char cc; cin >> cc;
}