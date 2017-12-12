#include "slist.h"

void create_list()
{
	slist<int> list;
	list.push_front(5);
	list.push_front(10);
	list.push_front(2);
	list.push_front(16);
	list.push_front(9);
}

int main()
{
	create_list();
	slist<int> list;
	list.push_front(5);
	list.push_front(10);
	list.push_front(2);
	list.push_front(16);
	list.push_front(9);

	char cc; cin >> cc;
}