#include "gods.h"

Link* Link::insert(Link* n)
{
	if (n == 0) return this;
	if (this == 0) return n;
	n->succ = this;
	if (prev) prev->succ = n;
	n->prev = prev;
	prev = n;

	return n;
}

void print_gods(Link* g)
{
	while (g)
	{
		cout << "Gott: " << g->god.name << "\n"
			<< "Mythologie: " << g->god.mythologie << "\n"
			<< "Waffe: " << g->god.waffe << "\n"
			<< "Fahrzeug: " << g->god.fahrzeug << "\n\n";
		g = g->next();
	}
}