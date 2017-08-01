#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//read file and invert words
void invert_w(string file)
{
	fstream fs(file, ios_base::in | ios_base::out);
	vector<string>words;
	string word;

	while (fs >> word)
		words.push_back(word);
	
	
	
	fs.clear();
	fs.seekp(0);

	for (int i = words.size() - 1; i >= 0; i--)
		fs << words[i] << " ";
		
	
}

int main()
{
	string filename = ".\\Test.txt";
	invert_w(filename);

	char cc; cin >> cc;
}