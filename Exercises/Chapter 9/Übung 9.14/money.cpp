#include "money.h"

namespace money_lib
{
	double runden(double dd)
	{
		int a = dd * 100;
		a = a * 10;
		int b = dd * 1000;
		int c = b - a;
		double result = a / 10;
		if (c >= 5)
			result = result + 1;
		
		return result / 100 ;
	}
	
	bool has_rest(double dd)
	{
		int a = dd * 100 ;
		double b = dd * 1000;
		b = b - a;

		return (b > 0);
	}

	Money::Money(double dd)
		:amount(runden(dd) * 100)
	{
		//if (has_rest(dd))
			//throw invalid();
	}

	Money::Money()
		:amount(0) {}

	double Money::get_amount() const
	{
		double d = amount;
		d = d / 100;
		return d;
	}

	void Money::set_amount(double dd)
	{
		amount = dd * 100;
	}

	double operator+(const Money& m, double d)
	{
		double result = m.get_amount() + d;
		return runden(result);
	}

	double operator-(const Money& m, double d)
	{
		double result = m.get_amount() - d;
		return runden(result);
	}

	double operator/(const Money& m, double d)
	{
		double result = m.get_amount() / d;
		return runden(result);
	}

	double operator*(const Money& m, double d)
	{
		double result = m.get_amount() * d;
		return runden(result);
	}

	ostream& operator<<(ostream& os,const Money& mm)
	{
		 os << mm.get_amount() << " Euro";
		 return os;
	}
}