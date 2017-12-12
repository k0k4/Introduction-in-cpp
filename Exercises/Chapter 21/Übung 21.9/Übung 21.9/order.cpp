#include "order.h"

//read Order objects out of a file
ifstream& operator>>(ifstream& is,Order& or)
{
	Purchase p;
	vector<Purchase> vp;
	char cc = ' ';
	string ss;
	//end of file 
	if (is >> ss && ss == "-")
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	or.setName(ss);
	is >> ss;
	or .setAdress(ss);
	while (cc != ';')
	{
		is >> p.name >> p.unit_price >> p.count >> cc;
		vp.push_back(p);
	}
	or .setPurchase(vp);

	return is;
}

ostream& operator<<(ostream& os,const Order& or )
{
	os << or.getName() << "\n" << or.getAdress() << "\n";
	for (int i = 0; i < or.getPurchases().size(); i++)
	{
		os << or.getPurchases()[i].name << " , " << or.getPurchases()[i].unit_price << " , " << or.getPurchases()[i].count << "\n";
	}

	return os;
}

ofstream& operator<<(ofstream& os, const Order& or )
{
	os << or .getName() << "\n" << or .getAdress() << "\n";
	for (int i = 0; i < or .getPurchases().size(); i++)
	{
		os << or .getPurchases()[i].name << " , " << or .getPurchases()[i].unit_price << " , " << or .getPurchases()[i].count << "\n";
	}

	return os;
}
void read_file(string filename, vector<Order>& order)
{
	Order or;
	ifstream is(filename);
	while (is >> or)
		order.push_back(or);

}

void print(const vector<Order>& or)
{
	for (int i = 0; i < or .size(); i++)
		cout << or [i];
}

void sort_order(vector<Order>& v)
{
	sort(v.begin(), v.end(), Cmp_by_name());
}

void write_file(string fileName, const vector<Order>& or)
{
	ofstream of(fileName);
	for (int i = 0; i < or .size(); i++)
		of << or [i];
}