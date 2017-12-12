#include <vector>
#include <random>
#include <iostream>

using namespace std;

class Room
{
public:
	bool wum, bat, hole;
	int num;

	Room* r1;
	Room* r2;
	Room* r3;

	Room(Room* rl = 0, Room* rr = 0, Room* rm = 0)
		:num(0), wum(false), bat(false), hole(false), r1(rl), r2(rr), r3(rm) {}
	Room(int n, Room* rl = 0, Room* rr = 0, Room* rm = 0)
		:num(n), wum(false), bat(false), hole(false), r1(rl), r2(rr), r3(rm) {}

	void room_con(Room*, Room*);
	Room* set_start();
};

struct Monster
{
	int room;
	char type;

	Monster()
		:room(0), type('x'){}
	Monster(int r, char c)
		:room(r), type(c){}

};

bool check_v(const vector<Monster>&, int);
vector<Monster> rand_monster(int b, int h);
Room* create_root();
Room* create_lab();
Room* rand_room(Room*);

void check_room(const vector<Monster>&, Room*);
void check_root(const vector<Monster>&, Room*);
void print(Room*);