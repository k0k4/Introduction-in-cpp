#include <list>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct Item
{
	string name;
	int id;
	double value;

	Item(string ss, int ii, double dd)
		:name(ss), id(ii), value(dd) {}
	Item() {};
};

list<Item> makel()
{
	list<Item> list;
	ifstream is("Items.txt");
	string name;
	int id;
	double val;

	while (is >> name >> id >> val)
	{
		Item item(name, id, val);
		list.push_back(item);
	}

	return list;
}

void printv(list<Item>& l)
{	
	list<Item>::iterator p;
	for (p = l.begin(); p != l.end(); ++p)
		cout << setw(10) << left << p->name << "\t" << p->id << '\t' << p->value << "\n";
	cout << "\n";
}

struct Cmp_by_id
{
	bool operator()(const Item& a,const Item& b) const
	{
		return a.id < b.id;
	}
};

struct Cmp_by_value
{
	bool operator()(Item* a, Item* b) const
	{
		return a->value > b->value;
	}
};

class find_name
{
	string s;
public:
	find_name(string ii)
		:s(ii) {}
	bool operator()(const Item& search) const
	{
		return search.name == s;
	}
};

class find_id
{
	int s;
public:
	find_id(int ii)
		:s(ii) {}
	bool operator()(const Item& search) const
	{
		return search.id == s;
	}
};



int main()
{
	list<Item> items = makel();
	printv(items);
	//sort name
	items.sort([](const Item& f, const Item& s) { return f.name < s.name; });
	printv(items);
	//sort id
	items.sort([](const Item& f, const Item& s) { return f.id < s.id; });
	printv(items);
	//sort value
	items.sort([](const Item& f, const Item& s) { return f.value > s.value; });
	printv(items);
	// +2 Items
	Item a("Hufeisen", 99, 12.34);
	Item b("Canon s400", 9988, 499.95);
	items.push_back(a);
	items.push_back(b);
	// delete 4 items
	list<Item>::iterator p = find_if(items.begin(), items.end(), find_name("Tomaten"));
	p = items.erase(p);
	p = find_if(items.begin(), items.end(), find_name("Brokoli"));
	p = items.erase(p);
	p = find_if(items.begin(), items.end(), find_id(117362));
	p = items.erase(p);
	p = find_if(items.begin(), items.end(), find_id(99));
	p = items.erase(p);
	printv(items);

	char cc; cin >> cc;
}
