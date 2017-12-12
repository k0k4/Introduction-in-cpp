#include "Int.h"

int main()
{
	Number<int>a(1);
	Number<int>b(3);

	a = b;
	
	cout << a.get();

	char cc; cin >> cc;
}