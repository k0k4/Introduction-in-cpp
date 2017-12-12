#include "game.h"

void print_rooms(Room* r)
{
	cout << "[Room " << r->r1->num << "] ," << "[Room " << r->r2->num << " ] ," << "[Room " << r->r3->num << " ]\n";
	if (r->r1->bat || r->r2->bat || r->r3->bat)
		cout << "I hear a bat\n";
	if (r->r1->hole || r->r2->hole || r->r3->hole)
		cout << "I feel wind\n";
	if (r->r1->wum || r->r2->wum || r->r3->wum)
		cout << "I smell the Wumpus\n";
}

Room* move(Room* r)
{
	int input;
	
	cin >> input;

	if (input == r->r1->num)
		return r->r1;
	else if (input == r->r2->num)
		return r->r2;
	else if (input == r->r3->num)
		return r->r3;
	else
		return r;
}

int check_monster(Room* r)
{
	if (r->wum)
	{
		cout << "U got eaten by the Wumpus, game over!\n";
		return 0;
	}

	else if (r->hole)
	{
		cout << "U fall into a hole and die, game over!\n";
		return 0;
	}
	else if (r->bat)
	{
		cout << "The bat got you! You hit the bat until it drops you down!\n";
		return 2;
	}
	else
		return 1;

}

Room* move_ran(Room*r)
{
	Room* current = r;

	for (int i = 0; i < 3; i++)
		current = rand_room(r);

	while (current->bat)
		current = rand_room(r);

	return current;
}

bool shoot(Room* r, int& a)
{
	Room* current = r;
	bool hit = false;
	int input;
	for (int i = 0; i < 3; i++)
	{
		//cout << "Choose room\n";
		cout << "[Room " << current->r1->num << "] ," << "[Room " << current->r2->num << " ] ," << "[Room " << current->r3->num << " ]\n";
		cin >> input;
		if (input == current->r1->num)
		{
			current = current->r1;
			if (current->wum)
				hit = true;
		}
		else if (input == current->r2->num)
		{
			current = current->r2;
			if (current->wum)
				hit = true;
		}
		else if (input == current->r3->num)
		{
			current = current->r3;
			if (current->wum)
				hit = true;
		}
	}
	a--;
	return hit;
}

bool start()
{
	Room* root = create_lab();
	int arrow = 5 , game = 1;
	string input;

	cout << "The Game starts, good luck!\n";
	while (game && arrow > 0)
	{
		print_rooms(root);
		cout << "What do you want to do?\n";
		cin >> input;
		if (input == "m")
		{
			root = move(root);
			game = check_monster(root);
			if (game == 2)
			{
				root = move_ran(root);
				game = check_monster(root);
			}
		}
		else if (input == "s")
		{
			if (shoot(root, arrow))
			{
				cout << "Congratulations you hit the wumpus game over!\n";
				break;
			}

			if (arrow == 0)
				cout << "No more arrows, you have no chance to kill the wumpus, game is over!\n";
		}
	}

	cout << "Do you want to play one more time?\n";
	cin >> input;

	if (input == "y")
		return true;
	else
		return false;

}

void game_loop()
{
	cout << "Welcome to Hunt the Wumpus\n";
	while (true)
	{
		if (start())
			continue;
		else
			break;
	}
}