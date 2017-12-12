#include <iostream>
#include <vector>

using namespace std;

vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(vector<int>& v)
{
	vector<int> lv(v.size());

	lv = v;

	for (int i = 0; i < lv.size(); i++)
		cout << "lv [" << i << "] =" << lv[i] << "\n";

	vector<int> lv2 = lv;

	for (int i = 0; i < lv2.size(); i++)
		cout << "lv2 [" << i << "] =" << lv2[i] << "\n";
}

int main()
{
	f(gv);

	vector<int> vv = { 1,2,3,4,5,6,7,8,9,10 };

	f(vv);

	char cc; cin >> cc;
}