#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool has_word(char c[], string word)
{
	string temp = "";

	for (int i = 0; i < 256; i++)
	{
		if (c[i] == ' ')
		{
			if (temp == word)
				return true;
			else
				temp = "";
		}
		else
			temp += c[i];	
	}
	return false;
}

//searching for a word in .txt file and return line if its found
void return_line(string filename, string word)
{
	ifstream istr(filename.c_str());
	int num = 1;
	char line[256];
	
	while (istr.getline(line, 256))
	{
		if (has_word(line, word))
			cout << line << " " << num << "\n";
		
		num++;
	}
}


int main()
{
	string file = ".\\Test.txt";
	string wordToFind;
	cout << "Pls insert Word to find\n";
	cin >> wordToFind;

	return_line(file, wordToFind);

	char cc; cin >> cc;
}
