#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//read and sort numbers
vector<int> read_and_sort(string file)
{
	vector<int>num;
	ifstream is(file);
	int i;

	while (is >> i)
		num.push_back(i);

	sort(num.begin(), num.end());

	return num;
}

//count num and put them out
void count(const vector<int>& num)
{
	int temp = num[0], count = 1;

	for (int i = 1; i < num.size(); i++)
	{
		if (num[i] != temp )
		{
			cout << num[i];
			if (count != 1)
			{
				cout << '\t' << count << '\n';
				count = 1;
			}

			else
				cout <<'\n';
			
			temp = num[i];
		}

		else
			count++;
	}

}

int main()
{
	string file = ".\\Test.txt";
	vector<int>numbers = read_and_sort(file);
	count(numbers);

	char cc; cin >> cc;
}