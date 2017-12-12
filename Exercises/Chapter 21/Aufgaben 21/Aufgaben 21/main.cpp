#include <vector>
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
		:name(ss), id(ii), value(dd){}
	Item() {};
};

vector<Item> makev()
{
	vector<Item> v;
	ifstream is("Items.txt");
	string name;
	int id;
	double val;

	while (is >> name >> id >> val)
	{
		Item item(name, id, val);
		v.push_back(item);
	}

	return v;
}

void printv(const vector<Item>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << setw(10)<< left << v[i].name << "\t" << v[i].id << '\t' << v[i].value << "\n";
	cout << "\n";
}

struct Cmp_by_name
{
	bool operator()(const Item& a, const Item& b)const
	{return a.name < b.name;}
};

struct Cmp_by_id
{
	bool operator()(const Item& a, const Item& b) const
	{return a.id < b.id;}
};

struct Cmp_by_value
{
	bool operator()(const Item& a, const Item& b) const
	{return a.value > b.value;}
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

template<class T>
class find_item
{
	T s;
public:
	find_item(T ii)
		:s(ii) {}
	bool operator()(const Item& search) const
	{
		return search.id == s;
	}
};


int main()
{
	vector<Item> items = makev();
	printv(items);
	//sort name
	sort(items.begin(), items.end(), Cmp_by_name());
	printv(items);
	//sort id
	sort(items.begin(), items.end(), Cmp_by_id());
	printv(items);
	//sort value
	sort(items.begin(), items.end(), Cmp_by_value());
	printv(items);
	// +2 Items
	Item a("Hufeisen", 99, 12.34);
	Item b("Canon s400", 9988, 499.95);
	items.push_back(a);
	items.push_back(b);
	// delete 4 items
	vector<Item>::iterator p = find_if(items.begin(), items.end(), find_name("Tomaten"));
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







