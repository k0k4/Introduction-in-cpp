#include <iostream>
#include <set>
#include <string>
#include <iterator>
using namespace std;

struct Fruit
{
	string name;
	int count;
	double unit_price;

	Fruit(string s, int c, double p)
		:name(s), count(c), unit_price(p) {};
};

ostream& operator<<(ostream& os, const Fruit* f)
{
	os << f->name;

	return os;
}

struct Fruit_comparison
{
	bool operator()(const Fruit* a, const Fruit* b) const
	{
		return a->name < b->name;
	}
};

int main()
{
	Fruit* f = new Fruit("test", 1, 1);
	set<Fruit*, Fruit_comparison> inventory;
	inventory.insert(new Fruit("Erdbeere", 2, 9.99));
	inventory.insert(new Fruit("Mango", 2, 100.99));
	
	typedef set<Fruit*>::const_iterator Sl;
	for (Sl p = inventory.begin(); p != inventory.end(); ++p) cout << *p << "\n";

	char cc; cin >> cc;
}