#include <iostream>
using namespace std;

template<class Elem> struct Link
{
	Link<Elem>(Link<Elem>* l1 = 0, Link<Elem>* l2 = 0)
		:prev(l1), succ(l2) {}
	Link<Elem>(Elem e, Link<Elem>* l1 = 0, Link<Elem>* l2 = 0)
		:val(e),prev(l1),succ(l2){}
	
	Link* prev;
	Link* succ;
	Elem val;
};


template<class Elem> class blist
{
	Link<Elem>* first;
	Link<Elem>* last;
public:
	blist<Elem>(Link<Elem>* fi = 0 ,Link<Elem>* la = 0)
		:first(fi), last(la){ }
	~blist<Elem>() { delete first; delete last; }

	class iterator;  //klasse ist auserhalb definiert
	
	iterator begin() { iterator p(first); return p; }
	iterator end() { iterator p(0); return p; }
	iterator insert(iterator p, const Elem& v);
	iterator erase(iterator p);
	
	void push_back(const Elem& v);
	void push_front(const Elem& v);
	void pop_front();
	void pop_back();

	Elem& front() { return first->val; }
	Elem& back() { return last->val; }
};

template<class Elem> class blist<Elem>::iterator
{
	Link<Elem>* curr;
public:
	iterator(Link<Elem>* p):curr(p){}

	iterator& operator++() { curr = curr->succ; return *this; }
	iterator& operator--() { curr = curr->prev; return *this; }
	Elem& operator*() { return curr->val; }
	Link<Elem>* get() { return curr; }

	bool operator==(const iterator& b) const { return curr == b.curr; }
	bool operator!=(const iterator& b) const { return curr != b.curr; }
};

template<class Elem>
void blist<Elem>::push_back(const Elem& v)
{
	if (last == 0 && first == 0)
	{
		Link<Elem>* link = new Link<Elem>(v);
		last = link;
		first = link;
	}

	else
	{
		Link<Elem>* link = new Link<Elem>(v);
		last->succ = link;
		link->prev = last;
		last = link;
	}
}
template<class Elem>
void blist<Elem>::push_front(const Elem& v)
{
	if (first == 0 && last == 0)
	{
		Link<Elem>* link = new Link<Elem>(v);
		last = link;
		first = link;
	}
	else
	{
		Link<Elem>* link = new Link<Elem>(v);
		link->succ = first;
		first->prev = link;
		first = link;
	}
}
template<class Elem>
void blist<Elem>::pop_front()
{
	if (last == first)
	{
		last = 0;
		first = 0;
	}
	else
	{
		first = first->succ;
		delete first->prev;
		first->prev = 0;
	}
}
template<class Elem>
void blist<Elem>::pop_back()
{
	if (last == first)
	{
		last = 0;
		first = 0;
	}
	else
	{
		last = last->prev;
		delete last->succ;
		last->succ = 0;
	}
}
template<class Elem>
typename blist<Elem>::iterator blist<Elem>::insert(typename iterator p, const Elem& v) 
{
	Link<Elem>* link = new Link<Elem>(v);
	link->prev = p.get();
	link->succ = p.get()->succ;
	link->prev->succ = link;
	p.get()->prev = link;
	return p;
}
template<class Elem>
typename blist<Elem>::iterator blist<Elem>::erase(typename iterator p)
{
	if (last == first)
	{
		first = 0;
		last = 0;
		return p;
	}
	else if (p.get() == first)
	{
		++p;
		first = p.get();
		delete p.get()->prev;
		p.get()->prev = 0;
		return p;
	}
	else if (p.get() == last)
	{
		--p;
		last = p.get();
		delete p.get()->succ;
		p.get()->succ = 0;
		return p;
	}
	else
	{
		p.get()->prev->succ = p.get()->succ;
		p.get()->succ->prev = p.get()->prev;
		return --p;
	}
}


