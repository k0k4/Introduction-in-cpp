#include <iostream>

using namespace std;

int ga[] = { 1,2,4,8,16,32,64,128,256,512 };

void f(int a[], int n)
{
	int la[10];
	
	for (int i = 0; i < n; i++)
		la[i] = a[i];

	for (int i = 0; i < n; i++)
		cout << "la[" << i << "] = " << la[i] << "\n";

	int* p = new int[n];

	for (int i = 0; i < n; i++)
		p[i] = a[i];

	for(int i = 0; i < n; i++)
		cout << "p[" << i << "] = " << p[i] << "\n";

	delete[] p;
}

int main()
{
	f(ga, 10);

	int aa[] = { 1,1 * 2,1 * 2 * 3,1 * 2 * 3 * 4,1 * 2 * 3 * 4 * 5,1 * 2 * 3 * 4 * 5 * 6,1 * 2 * 3 * 4 * 5 * 6 * 7,1 * 2 * 3 * 4 * 5 * 6 * 7 * 8,1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9,1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 };
	
	f(aa, 10);

	char cc; cin >> cc;
}