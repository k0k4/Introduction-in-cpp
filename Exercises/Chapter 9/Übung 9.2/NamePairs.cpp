#include "NamePairs.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace Paare;

	int Name_Pairs::new_position(string s, const vector<string>& v)
	{
		int new_pos = 0;
		for (int i = 0; i < names.size(); i++)
		{
			if (v[i] == s)
				new_pos = i;
		}

		return new_pos;
	}
	
	void Name_Pairs::read_names()
	{
		string eingabe;
		cout << "Bitte namen eingeben: ";
		cin >> eingabe;
		names.push_back(eingabe);
	}

	void Name_Pairs::read_ages()
	{
		for (int i = 0; i < names.size(); i++)
		{
			double eingabe;
			cout << "Alter von " << names[i] << " ist >>";
			cin >> eingabe;
			ages.push_back(eingabe);
		}
	}

	void Name_Pairs::sort_pairs()
	{
		vector<string>tempN = names;
		vector<double>tempA = ages;
		int new_pos = 0 , temp = 0;
		sort(names.begin(), names.end());

		for (int i = 0; i < names.size(); i++)
		{
			new_pos = new_position(tempN[i], names);
			ages[new_pos] = tempA[i];
		}

	}

	void Name_Pairs::print()
	{
		for (int i = 0; i < names.size(); i++)
		{
			cout << names[i] << " " << ages[i] << "\n";
		}
	}

	
	
