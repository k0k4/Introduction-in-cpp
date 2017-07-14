#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//function to copy file into another
void read_file(const string file1, const string file2)
{
	ifstream istr(file1.c_str());
	ofstream ostr;	
	ostr.open(file2, fstream::app);

	char c[256];

	while (istr.getline(c, 256))
		ostr << c << "\n" ;
	
	ostr.close();
}

int main()
{
	string inFile1 = ".\\Text1.txt";
	string inFile2 = ".\\Text2.txt";
	string outFile = ".\\out.txt";

	read_file( inFile1, outFile);
	read_file( inFile2, outFile);
}