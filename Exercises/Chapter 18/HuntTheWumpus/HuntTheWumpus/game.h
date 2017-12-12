#include "room.h"
#include <string>

using namespace std;


Room* move(Room*);
Room* move_ran(Room*);
int check_monster(Room*);
bool shoot(Room*, int& );
void print_rooms(Room*);
bool start();
void game_loop();


