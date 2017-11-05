#include <iostream>
#include <vector>
using namespace std;

int* int_array(int n)
{
	int* ar = new int[n];
	int temp = 1;
	for (int i = 0; i < n; i++)
	{
		temp *= 2;
		ar[i] = temp;
	}
		

	return ar;
}

int* int_array1(int n)
{
	int* ar = new int[n];
	for (int i = 0; i < n; i++)
		ar[i] = i;


	return ar;
}

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; i++)
		os << a[i] << '\n';
}

vector<int> int_vector(int n)
{
	vector<int> v;
	int temp = 100;
	for (int i = 0; i < n; i++)
		v.push_back(temp++);

	return v;
}

void print_vector(ostream& os, vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		os << v[i] << '\n';
}

int main()
{
	int* p1 = int_array(10);
	int* p2 = int_array1(10);
	
	print_array(cout, p1, 10);
	print_array(cout, p2, 10);

	int* p3 = p1;
	p1 = p2;
	p2 = p3;

	print_array(cout, p1, 10);
	print_array(cout, p2, 10);

	char cc; cin >> cc;
}