#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void fill_vs(vector<string>& v)
{
	
	string eingabe;
	cout << "namen eingeben: \n";

	while (cin >> eingabe)
	{
		if (eingabe == "noname")
			break;
		else
			v.push_back(eingabe);
	}

}

void fill_va(vector<double>& va,vector<string>& vs)
{
	double eingabe;
	cout << "alter angeben : \n";

	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << "'s alter ist: ";
		cin >> eingabe;
		va.push_back(eingabe);
	}

}

void print_v(const vector<string>& vs, const vector<double>& va)
{
	for (int i = 0; i < va.size(); i++)
		cout << "Name: " << vs[i] << ", Alter: " << va[i] << "\n";
}

void change_v(const vector<string>& vnc, const vector<string>& vn, vector<double>& va,vector<double>& vac)
{
	int neuePos = 0;

	for (int i = 0; i < vnc.size(); i++)
	{
		for (int j = 0; j < vnc.size(); j++)
		{
			if (vnc[i] == vn[j])
			{
				neuePos = j;

			}
				
		}
		
		int temp = va[i];
		vac[neuePos] = temp;
		

	}
		
}

int main()
{
	vector<string>namen;
	vector<double>age;

	fill_vs(namen);
	fill_va(age,namen);
	print_v(namen, age);

	vector<string>namenCopy = namen;
	vector<double>ageCopy = age;

	sort(namen.begin(), namen.end());
	print_v(namen, age);
	change_v(namenCopy, namen, age,ageCopy);
	print_v(namen, ageCopy);

	char cc; cin >> cc;
}