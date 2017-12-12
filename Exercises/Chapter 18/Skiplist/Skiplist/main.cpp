
#include "skiplist.h"

using namespace std;

int main()
{
	Link* root = new Link(0, 0, true);
	root = root->insert(5);
	root = root->insert(3);
	root = root->insert(10);
	root = root->insert(6);
	root = root->insert(9);

	//root->print();

	//root->del_el(5);

	root->print();

	if (root->find(10))
		cout << "Found it!\n";
	else
		cout << "not found!\n";

	char cc; cin >> cc;
}