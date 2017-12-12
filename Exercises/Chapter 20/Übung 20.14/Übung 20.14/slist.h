#include <iostream>
using namespace std;
template<class Elem> struct Link
{
	Link(Link* su = 0)
		:succ(su){}
	Link(Elem e,Link* su = 0)
		:val(e), succ(su) {}

	Link* succ;
	Elem val;
};

template<class Elem> class slist
{
	Link<Elem>* first;
	Link<Elem>* last;
	Link<Elem>* des;
public:
	slist(Link<Elem>* fi = 0, Link<Elem>* la = 0, Link<Elem>* de = 0)
		:first(fi),last(la),des(de){}
	~slist();
	class iterator;

	iterator begin() { iterator p(first); return p; }
	iterator end() {iterator p(0); return p; }
	
	void push_front(Elem e);
	void push_back(Elem e);
	void pop_front();
	
	Elem& front();
	Elem& back();

};

template<class Elem> class slist<Elem>::iterator
{
	Link<Elem>* curr;
public:
	iterator(Link<Elem>* p) : curr(p) {}

	iterator& operator++() { curr = curr->succ; return *this; }
	Elem& operator*() { return curr->val; }
	
	bool operator==(const iterator& p) const { return curr == p.curr; }
	bool operator!=(const iterator& p) const { return curr != p.curr; }

};
template<class Elem>
void slist<Elem>::push_front(Elem e)
{	
	if (first == 0 && last == 0)
	{
		Link<Elem>* link = new Link<Elem>(e);
		des = link;
		first = link;
		last = link;
	}
	else
	{
		Link<Elem>* link = new Link<Elem>(e);
		link->succ = first;
		first = link;
		des = first;
	}
	
}
template<class Elem>
void slist<Elem>::push_back(Elem e)
{
	if (first == 0 && last == 0)
	{
		Link<Elem>* link = new Link<Elem>(e);
		first = link;
		last = link;
	}
	else
	{
		Link<Elem>* link = new Link<Elem>(e);
		last->succ = link;
		last = link;
	}

}
template<class Elem>
void slist<Elem>::pop_front()
{
	if (last == first)
	{
		last = 0;
		first = 0;
	}
	else
		first = first->succ;
}

template<class Elem>
Elem& slist<Elem>::front()
{
	return first->val;
}

template<class Elem>
Elem& slist<Elem>::back()
{
	return last->val;
}

template<class Elem> slist<Elem>::~slist()
{
	Link<Elem>* temp = des;
	while (temp->succ != 0)
	{
		Link<Elem>* temp2 = temp;
		temp = temp->succ;
		delete temp2;
		cout << "del ele\n";
	}
	cout << "finished\n";
	delete temp;

}




