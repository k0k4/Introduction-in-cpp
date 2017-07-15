#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//calculate sum of integer out of .txt file
//format string, int, string ,int ...
int sum_int(string filename)
{
	int sum = 0, read_int;
	string read_string;

	ifstream istr(filename.c_str());

	while (istr >> read_string)
	{
		istr >> read_int;
		sum += read_int;
	}

	return sum;
}

int main()
{
	string file = ".\\Text.txt";
	int result = sum_int(file);

	cout << result;

}