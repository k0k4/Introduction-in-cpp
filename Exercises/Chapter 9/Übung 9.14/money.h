#include <string>
#include <iostream>

using namespace std;

namespace money_lib
{
	class Money
	{
	public:
		class invalid {};
		
		Money(double dd);
		Money();

		//read
		double get_amount() const;

		//write
		void set_amount(double dd);

	private:
		//in euro
		long amount;
	};

	//operators

	double operator+(const Money& m, double d);
	double operator-(const Money& m, double d);
	double operator/(const Money& m, double d);
	double operator*(const Money& m, double d);
	ostream& operator<<(ostream& os,const Money& mm);

	//functions

	double runden(double dd);
	bool has_rest(double dd);
}
