#include <vector>
#include <iostream>

using namespace std;

void print_v(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}

void swap_v(vector<int>& v)
{
	
	
	for (int i = v.size() -1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int temp = v[j];
			v[j] = v[j + 1];
			v[j + 1] = temp;
		}
	}
}


int main()
{
	vector<int> test(5);
	test[0] = 9;
	test[1] = 7;
	test[2] = 5;
	test[3] = 3;
	test[4] = 1;

	

	print_v(test);
	swap_v(test);
	print_v(test);

	char cc; cin >> cc;
}