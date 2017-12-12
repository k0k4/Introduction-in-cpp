#include "skiplist.h"

using namespace std;

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> dis(0, 1);

//put root in if needed
Link* insert_root(Link* l, int coin)
{
	Link* p = l;
	Link* np = 0;
	
	while (p->hight < coin)
		{
			/*
			np = new Link(0, p->hight + 1, true);
			p->set_top(np);
			np->set_bot(p);
			p = p->up();*/

			p->set_top (new Link(0, p->hight + 1, true));
			p->up()->set_bot(p);
			p = p->up();
		}
	return p;
}

void insert_link(Link* l, int coin, int v)
{
	bool finished = false;
	Link* current = l;
	Link* lastinsert = new Link(v, coin);

	while (!finished)
	{

		if (current->hight <= coin)
		{
			//skippen
			while (current->next() != 0 && current->next()->value <= v)
				current = current->next();

			if (current->next() == 0)
				current->set_right(lastinsert);
			else
			{
				lastinsert->set_right(current->next());
				current->set_right(lastinsert);
			}

			if (current->hight == 0)
				finished = true;
			else
			{
				lastinsert->set_bot(new Link(v, (lastinsert->hight - 1)));
				lastinsert = lastinsert->down();
				current = current->down();
			}
		}
		else
		{
			while (current->next() != 0 && current->next()->value <= v)
				current = current->next();

			if (current->down() != 0)
				current = current->down();
		}

	}
}
//put a Link in Line
Link* Link::insert(int v)
{
	Link* current = this;
	int coin = 0;
	
	//flip coin
	while (dis(gen))
		coin++;
	Link* lastinsert = new Link(v, coin);
	//insert new root links if coin flip is bigger than current hight
	if (coin > current->hight)                 
		current = insert_root(current, coin);
	//insert new link	
	insert_link(current, coin, v);
	
	return current;

}

void Link::print()
{

	Link* p = this;
	Link* root = this;

	for(int i = root->hight; i >= 0; i--)
	{
		while (p)
		{
			if (p->is_root)
				cout << "[root" << p->hight << "] -> ";
			else
				cout << "[" << p->value << "]" << "->";
			
			p = p->next();
		}

		cout << "\n";
		if (root->bot)
		{
			root = root->down();
			p = root;
		}
	
	}
}

bool Link::find(int v)
{
	Link* current = this;
	
	while (current)
	{
		while (current->next() != 0 && current->next()->value <= v)
			current = current->next();

		if (current->value == v)
			return true;
		else
			current = current->down();
		
	}

	return false;
}

void Link::del_el(int v)
{
	Link* current = this;

	while (current)
	{
		while (current->next() != 0 && current->next()->value < v)
			current = current->next();
		
		if (current->next() == 0)
			current = current->down();
		else
		{
			if (current->next()->value == v)
			{
					current->set_right(current->next()->next());
					current = current->down();
			}
			else
				current = current->down();
		}
	}
}