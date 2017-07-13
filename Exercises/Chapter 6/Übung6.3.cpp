// Übung6.3.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

class Name_value
{
public:
	string name;
	int age;
	Name_value(string n, int a)
		:name(n), age(a) {}
};

int main()
{
    
	string name;
	int alter;
	

	vector<Name_value>speicher;

	while (cin >> name >> alter)
	{
		if (name == "noname" && alter == 0)
			break;
		else
		{
			Name_value temp(name, alter);
			speicher.push_back(temp);
		}
			
	}

	for (int i = 0; i < speicher.size(); i++)
		cout << speicher[i].name << " " << speicher[i].age << "\n";
	
	return 0;
}

