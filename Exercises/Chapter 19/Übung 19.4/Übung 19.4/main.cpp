#include "gods.h"

int main()
{
	God god("Thor", "Germanisch", "Hammer", "keine");
	Link<God>* root = new Link<God>(god);


	god.name = "Frey"; god.mythologie = "Germanisch"; god.waffe = "Stab";
	root = root->insert(new Link<God>(god));

	god.name = "Odin"; god.mythologie = "Germanisch"; god.waffe = "Blitz";
	root = root->insert(new Link<God>(god));
	
	char cc; cin >> cc;
}