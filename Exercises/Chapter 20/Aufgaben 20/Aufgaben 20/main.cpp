#include <vector>
#include <iostream>
#include <list>
using namespace std;
template<class Iterator>
void add_int(Iterator a, Iterator b, int n)
{
	for (Iterator i = a; i != b; ++i)
		*i += n;
}

template<class Iterator>
void print_int(Iterator a, Iterator b)
{
	for (Iterator i = a; i != b; ++i)
		cout << *i << ", ";
	cout << "\n";
}

template<class Iter1, class Iter2> Iter2 copy_(Iter1 f1, Iter1 e1, Iter2 f2)
{
	if (f1 == e1)
	{
		cout << "is empty \n";
		return f2;
	}

	while (f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}

	return f2;
}

template<class Iter>
int get_pos(Iter a, Iter b)
{
	int count = 0;
	for (Iter p = a; p != b; ++p)
		count++;
	return count;
}

int main()
{
	int ar[] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	list<int> l = { 0,1,2,3,4,5,6,7,8,9 };



	add_int(ar,ar + 10, 2);
	print_int(ar, ar + 10);

	add_int(v.begin(), v.end(), 3);
	print_int(v.begin(), v.end());

	add_int(l.begin(), l.end(), 4);
	print_int(l.begin(), l.end());
	
	vector<int>::iterator vi = copy_(ar, ar + 10, v.begin());
	print_int(v.begin(), v.end());

	int* Iptr = copy(l.begin(), l.end(), ar);
	print_int(ar, ar + 10);

	vector<int>::iterator vi2 = find(v.begin(), v.end(), 3);
	if (vi2 != v.end())
	{
		cout << "found element!\n";
		cout << get_pos(v.begin(), vi2);
	}
	else
		cout << "element not found :(\n";

	list<int>::iterator l2 = find(l.begin(), l.end(), 27);
	if (l2 != l.end())
	{
		cout << "found element!\n";
		cout << get_pos(l.begin(), l2);
	}
	else
		cout << "element not found :(\n";

	char cc; cin >> cc;
}