
using namespace std;



namespace Paare
{
	class Name_Pairs
	{
	public:
		void read_names();
		void read_ages();
		void print();

		void sort_pairs();
		vector<string>names;
		vector<double>ages;
	
	private:
		
		int new_position(string, const vector<string>&);

	};

}
