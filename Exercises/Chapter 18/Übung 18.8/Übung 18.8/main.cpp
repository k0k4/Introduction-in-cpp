#include <iostream>
#include <string>

using namespace std;

bool is_palindrome1(const string& s)
{
	string copy;
	for (int i = s.length() - 1; i >= 0; i--)
		copy += s[i];

	for (int i = 0; i < s.length(); i++)
		if (s[i] != copy[i])
			return false;

	return true;
}

bool is_palindrome2(const char s[], int n)
{
	char* copy = new char[n];
	for(int i = strlen(s) - 1; i >= 0; i--)
	{
		*copy = s[i];
		copy++;
	}
	copy -= strlen(s);

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != copy[i])
			return false;
		
	}

	return true;
}

bool is_palindrome3(const char* first, const char* last)
{
	int size = 0;
	int i = 0;
	while (first[i] != 0)
	{
		size++;
		i++;
	}
		
	char* copy = new char[size];

	for (int i = size - 1; i >= 0; i--)
	{
		*copy = first[i];
		copy++;
	}

	copy -= size;

	for (int i = 0; i < size; i++)
		if (first[i] != copy[i])
			return false;

	return true;
}

int main()
{
	string palin1 = "otto";
	char palin2[] = "otto";

	if (is_palindrome3(&palin2[0], &palin2[3]))
		cout << "Is palindrome";
	else
		cout << "is none";

	char cc; cin >> cc;
}