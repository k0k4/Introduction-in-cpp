#include "NamePairs.h"

using namespace Paare;

ostream& operator<<(ostream& os,const Name_Pairs& np)
{
	
	
	for (int i = 0; i < np.names.size(); i++)
	{
		 os << np.names[i] << " " << np.ages[i] << "\n";
	}

	return os;
}

int main()
{
	Name_Pairs test;
	
	for (int i = 0; i < 5; i++)
	{
		test.read_names();
	}
	
	test.read_ages();
	test.sort_pairs();
	//test.print();
	cout << test;
	char cc; cin >> cc;
}