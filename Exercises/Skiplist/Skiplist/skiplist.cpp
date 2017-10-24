#include "skiplist.h"

using namespace std;

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> dis(0, 1);
//put a Link in Line
Link* Link::insert(int v)
{
	Link* current = this;
	Link* root = 0;
	int coin = 0;
	bool finished = false;

	while (dis(gen))
		coin++;

	Link* lastinsert = new Link(v, coin);
	cout << "\nCurrent hight = " << current->hight << "\n";
	cout << "coin flip = " << coin << "\n";
	//insert root links if needed
	if (coin >= current->hight)
	{
		if (current->hight == coin)
		{
			current->top = new Link(0, coin + 1, true);
			current->top->bot = current;
			current = current->up();
			
		}
		else
			while (current->hight < (coin + 1))
			{
				current->top = new Link(0, current->hight + 1, true);
				current->top->bot = current;
				current = current->up();
			}
	}
	
	root = current;
	//cout << "Root hight = "<< root->hight <<"\n";
	
	cout << "current value, height = " << current->value << " " << current->hight << "\n";
	cout << "lastinsert value, height = " << lastinsert->value << " " << lastinsert->hight << "\n";
	//insert link
	int h = current->hight;
	while (!finished)
	{
		cout << " h = " << h-- << "\n";

		if (current->hight <= coin)
		{
			//skippen
			while (current->right != 0 && current->right->value <= v)
				current = current->next();

			cout << "Skip to " << current->value << " " << "\n";
			
			if (current->right == 0)
			{
				current->right = lastinsert;
				cout << "current-> right = " << lastinsert->value << "\n";
			}
			else
			{
				lastinsert->right = current->right;
				cout << "Lastinsert->right = " << lastinsert->right->value << "\n";
				current->right = lastinsert;
				cout << "currrent->right = " << lastinsert->value << "\n";
			}
			
			if (current->hight == 0)
				finished = true;
			else
			{
				lastinsert->bot = new Link(v, (lastinsert->hight - 1));
				cout << "lastinsert->bot = " << lastinsert->bot->value << "\n";
				lastinsert = lastinsert->down();
				cout << "lastinsert = " << lastinsert->value << "\n";
				current = current->down();
				cout << "current = " << current->value << "\n";
			}
		}
		else
		{
			while (current->right != 0 && current->right->value <= v)
				current = current->next();
			
			cout << "Skip to " << current->value << " " << "\n";

			if (current->bot != 0)
			{
				current = current->down();
				cout << "Go down to " << current->value << " " << "\n";
			}
		}

	}

	return root;
	
}


void Link::print()
{
	
	Link* p = this;
	

	while (p)
	{
		cout << p->value;
		if (p = p->next())
			cout << ", ";
		
		
	}
}