#include <iostream>
#include <random>

using namespace std;
class Link
{
public:
	int value;
	int hight;
	bool is_root = false;

	Link(int v, int h, bool root, Link* t = 0, Link* r = 0, Link* b = 0, Link* l = 0 )
		:value(v),hight(h),is_root(root),top(t),right(r),bot(b),left(l){}
	Link(int v, int h, Link* t = 0, Link* r = 0, Link* b = 0, Link* l = 0)
		:value(v),hight(h), top(t), right(r), bot(b), left(l) {}

	Link(const Link& l) { value = l.value; is_root = l.is_root; top = l.top; right = l.right; bot = l.bot; left = l.left; }
	//Link(Link* l) { value = l->value; is_root = l->is_root; top = l->top; right = l->right; bot = l->bot; left = l->left; }
	Link& operator=(const Link& l) { value = l.value; is_root = l.is_root; top = l.top; right = l.right; bot = l.bot; left = l.left; return *this; }
	
	Link* insert(int v);
	void print();
	
	Link* up() const { return top; };
	Link* next() const { return right; };
	Link* down() const { return bot; };
	Link* back() const { return left; };
	

private:
	Link* top;
	Link* right;
	Link* bot;
	Link* left;
};

