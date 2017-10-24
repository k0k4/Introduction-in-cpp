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
	
	/*
	root->insert(new Link(5));
	root->insert(new Link(3));
	root->insert(new Link(10));
	root->insert(new Link(6));
	root->insert(new Link(9));
	*/


	char cc; cin >> cc;
}