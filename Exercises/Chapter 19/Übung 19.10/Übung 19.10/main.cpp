#include <iostream>
using namespace std;

struct Int
{
	int x;
	Int(int xx)
		:x(xx){}
};

class auto_ptr
{
	Int* ptr;
public:
	
	auto_ptr(Int* val)
		:ptr(val) {}
	~auto_ptr() { delete ptr; }

	int operator*() { return ptr->x; }
	Int* operator->() { return ptr ; }
	Int* release() { return ptr; }
};

int main()
{
	auto_ptr ptr1(new Int(10));

	cout << ptr1->x;

	char cc; cin >> cc;
}