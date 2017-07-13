#include "money.h"

using namespace money_lib;

int main()
{
	
	try
	{
		Money mymoney(100.222);
		mymoney = mymoney * 3;
		cout << mymoney << "\n";

	}
	catch (Money::invalid)
	{
		cout << "Geht nich lol";
	}

	char cc; cin >> cc;
}