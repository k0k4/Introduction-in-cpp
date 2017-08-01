#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

template<class T>
char* as_bytes(T& i)
{
	void* addr = &i;

	return static_cast<char*>(addr);
}

//convert .txt file to binary file
void txtTobinary(string filetext, string filebin)
{
	ifstream is(filetext.c_str(), ios_base::binary);
	ofstream os(filebin.c_str(), ios_base::binary);
	vector<int>bin;

	int i;
	while (is.read(as_bytes(i), sizeof(int)))
		bin.push_back(i);

	for (int i = 0; i < bin.size(); i++)
		os.write(as_bytes(bin[i]), sizeof(int));
	
}

//convert binary file to .txt file
void binaryTotxt(string binFile, string txtFile)
{
	ifstream is(binFile.c_str(), ios_base::binary);
	ofstream os(txtFile.c_str());
	vector<int>bin;
	
	int i;
	while (is.read(as_bytes(i), sizeof(int)))
		bin.push_back(i);

	for (int i = 0; i < bin.size(); i++)
		os.write(as_bytes(bin[i]), sizeof(int));
}

int main()
{
	string file = ".\\Text.txt";
	string binOut = ".\\TextBin";
	string txtOut = ".\\TextOut.txt";

	txtTobinary(file, binOut);
	binaryTotxt(binOut, txtOut);

	char cc; cin >> cc;
}