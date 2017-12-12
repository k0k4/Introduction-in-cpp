#include "room.h"

bool check_v(const vector<Monster>& v, int test)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (test == v[i].room)
			return true;
	}

	return false;
}
//put game objects in lab, b = bat count, h = hole count
vector<Monster> rand_monster(int b, int h)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 14);

	int rand_int = 0;
	vector<Monster> v;
	Monster temp(dis(gen), 'w');
	v.push_back(temp);

	for (int i = 0; i < b; i++)
	{
		while (true)
		{
			rand_int = dis(gen);
			if (check_v(v, rand_int))
				continue;
			else
				break;
		}
		temp.room = rand_int;
		temp.type = 'b';
		v.push_back(temp);
	}

	for (int i = 0; i < h; i++)
	{
		while (true)
		{
			rand_int = dis(gen);
			if (check_v(v, rand_int))
				continue;
			else
				break;
		}
		temp.room = rand_int;
		temp.type = 'h';
		v.push_back(temp);
	}

	return v;
}



Room* create_root()
{
	Room* root = new Room();

	root->r1 = new Room();
	root->r2 = new Room();
	root->r3 = new Room();

	root->num = 1;
	root->r1->num = 2;
	root->r2->num = 3;
	root->r3->num = 4;

	root->r1->r3 = root;
	root->r1->r2 = root->r3;
	root->r1->r1 = root->r2;

	root->r2->r3 = root->r1;
	root->r2->r2 = root;
	root->r2->r1 = root->r3;

	root->r3->r1 = root;
	root->r3->r2 = root->r1;
	root->r3->r3 = root->r2;

	return root;
}

void check_room(const vector<Monster>& m, Room* r)
{
	for (int i = 0; i < m.size(); i++)
		if (m[i].room == r->num)
		{
			if (m[i].type == 'w')
				r->wum = true;
			else if (m[i].type == 'b')
				r->bat = true;
			else if (m[i].type == 'h')
				r->hole = true;
		}
}

void check_root(const vector<Monster>& m, Room* root)
{
	check_room(m, root);
	check_room(m, root->r1);
	check_room(m, root->r2);
	check_room(m, root->r3);
}

Room* rand_room(Room* root)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 3);

	int rand_int = dis(gen);

	if (rand_int == 1)
		return root->r1;
	else if (rand_int == 2)
		return root->r2;
	else if (rand_int == 3)
		return root->r3;
}

void Room::room_con(Room* rom, Room* rom2)
{
	Room* p = this;
	if (p->r1->r1->num == p->num)
	{
		p->r1->r1 = rom;
		rom->r3 = p->r1;
	}
		
	else if (p->r1->r2->num == p->num)
	{
		p->r1->r2 = rom;
		rom->r3 = p->r1;
	}
	else if (p->r1->r3->num == p->num)
	{
		p->r1->r3 = rom;
		rom->r3 = p->r1;
	}

	if (p->r3->r1->num == p->num)
	{
		p->r3->r1 = rom2;
		rom2->r1 = p->r3;
	}
	else if (p->r3->r2->num == p->num)
	{
		p->r3->r2 = rom2;
		rom2->r1 = p->r3;
	}
	else if (p->r3->r3->num == p->num)
	{
		p->r3->r3 = rom2;
		rom2->r1 = p->r3;
	}
}

 void print(Room* r)
{
	 cout << "[Room " << r->num << "]->" << r->r1->num << "->" << r->r2->num << "->" << r->r3->num << "\n";
}
 
Room* Room::set_start()
 {
	 Room* p = this;

	 for (int i = 0; i < 5; i++)
		 p = rand_room(p);

	 while (true)
	 {
		 if (p->bat || p->hole || p->wum)
		 {
			 p = rand_room(p);
			 continue;
		 }

		 else
			 break;
	 }

	 return p;
 }

Room* create_lab()
{
	vector<Monster> mon = rand_monster(1, 1);
	int roomC = 5;
	Room* rtemp1 = 0;
	Room* rtemp2 = 0;
	Room* root = create_root();
	check_root(mon, root);

	for (int i = 0; i < 5; i++)
	{
		root = rand_room(root);
		
		rtemp1 = new Room(roomC++);
		rtemp2 = new Room(roomC++);
		check_room(mon, rtemp1);
		check_room(mon, rtemp2);

		root->room_con(rtemp1, rtemp2);
		
		root->r1 = rtemp1;
		root->r3 = rtemp2;

		rtemp1->r2 = root;
		rtemp2->r2 = root;

		rtemp1->r1 = rtemp2;
		rtemp2->r3 = rtemp1;
		
	}

	root = root->set_start();

	return root;
}

