#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//read words into vector
void read_words(vector<string>& v, string filename)
{
	ifstream istr(filename.c_str());

	string read;

	while (istr >> read)
		v.push_back(read);
}

int main()
{
	string filename1 = ".\\Text1.txt";
	string filename2 = ".\\Text2.txt";
	vector<string>words;

	read_words(words, filename1);
	read_words(words, filename2);
	sort(words.begin(), words.end());

}