#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

//read file and invert chars
void invert_c(string file)
{
	fstream fs(file.c_str(), ios_base::in | ios_base::out);
	vector<char>store;
	char ch;
	
	while (fs.get(ch))
			store.push_back(ch);
		
	
	fs.clear();
	fs.seekp(0);

	for (int i = store.size() -1 ; i >= 0; i--)
	{
		fs << store[i];
	}
}

int main()
{
	string test = ".\\Test.txt";
	invert_c(test);
	
	char cc; cin >> cc;
}