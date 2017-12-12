#include "order.h"

int main()
{
	vector<Order> orders;
	read_file("data.txt", orders);
	sort_order(orders);
	print(orders);
	write_file("data.txt", orders);
	char cc; cin >> cc;
}