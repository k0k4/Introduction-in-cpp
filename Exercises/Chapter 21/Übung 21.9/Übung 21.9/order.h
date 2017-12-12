#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct Purchase
{
	string name;
	double unit_price;
	int count;

	Purchase() {};
};

class Order
{
	string name;
	string adress;
	vector<Purchase> purchases;
public:
	Order(string na, string ad, const vector<Purchase>& v)
		:name(na), adress(ad), purchases(v) {};
	Order() {};

	void setName(string s) { name = s; }
	void setAdress(string s) { adress = s; }
	void setPurchase(const vector<Purchase>& p) { purchases = p; }
	string getName() const { return name; }
	string getAdress() const { return adress; }
	vector<Purchase> getPurchases() const { return purchases; }
};

struct Cmp_by_name
{
	bool operator()(const Order& a, const Order& b) const
	{
		return a.getName() < b.getName();
	}
};

ifstream& operator>>(ifstream&, const Order&);
ostream& operator<<(ostream&, const Order&);

void read_file(string, vector<Order>&);
void write_file(string,const vector<Order>&);
void print(const vector<Order>&);
void sort_order(vector<Order>&);