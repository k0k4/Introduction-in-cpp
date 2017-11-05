#include <iostream>
#include <string>
#include "gods.h"

using namespace std;

int main()
{
	
	God god("Thor", "Germanisch", "Hammer", "");
	Link* norse_gods = new Link(god);

	god.name = "Frey"; god.mythologie = "Germanisch"; god.waffe = "Stab";
	norse_gods = norse_gods->insert(new Link(god));

	god.name = "Odin"; god.mythologie = "Germanisch"; god.waffe = "Blitz";
	norse_gods = norse_gods->insert(new Link(god));

	print_gods(norse_gods);

	char cc; cin >> cc;
}