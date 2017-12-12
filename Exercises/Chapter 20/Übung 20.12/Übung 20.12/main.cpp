#include "blist.h"

int main()
{
	blist<int> i;

	i.push_back(5);
	i.push_back(8);
	i.push_front(11);
	i.push_front(15);

	i.pop_front();
	i.pop_back();
	blist<int>::iterator p = i.begin();
	p = i.insert(p, 7);
	p = i.erase(p);
	for (blist<int>::iterator b = i.begin(); b != i.end(); ++b)
		cout << *b << ", "  ; 
	cout << "end";

	char cc; cin >> cc;
}