#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void show_dec(string s)
{
	int a = stoi(s);
	cout << showbase << dec << setw(7) << a << setw(12) << " dezimal" << " umgewandelt in " << setw(7) << dec << a << " dezimal\n";
}

void show_hex(string s)
{
	string out;
	for (int i = 2; i < s.size(); i++)
		out += s[i];

	int a = stoi(out);
	cout << showbase << hex << setw(7) << a << setw(12) << " hexadezimal" << " umgewandelt in " << setw(7) << dec << a << " dezimal\n";
}

void show_oct(string s)
{
	string out;
	for (int i = 1; i < s.size(); i++)
		out += s[i];

	int a = stoi(out);
	cout << showbase << oct << setw(7) << a << setw(12) << " octal" << " umgewandelt in " << setw(7) << dec << a << " dezimal\n";
}

void test_string(string s)
{
	if (s[0] == '0')
	{
		if (s[1] == 'x')
			show_hex(s);
		else
			show_oct(s);
	}
	else
		show_dec(s);
}

//Read numbers and put them out
void read_num()
{
	string input;
	while (cin >> input)
		test_string(input);
	
}

int main()
{
	read_num();
	char cc; cin >> cc;
}