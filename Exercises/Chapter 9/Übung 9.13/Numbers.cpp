#include "Numbers.h"

namespace rational_lib
{
	Rational::Rational(int a, int b)
		:counter(a), namer(b) {}

	Rational::Rational()
		:counter(0), namer(0) {}

	ostream& operator<<(ostream& os, const Rational& r)
	{
		os << r.get_counter() << "/" << r.get_namer() ;

		return os;
	}

	Rational operator+(const Rational a, const Rational b)
	{
		Rational r;
		if (a.get_namer() == b.get_namer())
		{
			r.set_namer(a.get_namer());
			r.set_counter(a.get_counter() + b.get_counter());
		}

		else
		{
			r.set_counter((a.get_counter() * b.get_namer()) + (a.get_namer() * b.get_counter()));
			r.set_namer(a.get_namer() * b.get_namer());
		}

		return r;
	}

	Rational operator-(const Rational a, const Rational b)
	{
		Rational r;
		if (a.get_namer() == b.get_namer())
		{
			r.set_namer(a.get_namer());
			r.set_counter(a.get_counter() - b.get_counter());
		}

		else
		{
			r.set_counter((a.get_counter() * b.get_namer()) - (a.get_namer() * b.get_counter()));
			r.set_namer(a.get_namer() * b.get_namer());
		}

		return r;
	}

	Rational operator/(const Rational a, const Rational b)
	{
		Rational r;
		r.set_counter(a.get_counter() * b.get_namer());
		r.set_namer(a.get_namer() * b.get_counter());

		return r;
	}

	Rational operator*(const Rational a, const Rational b)
	{
		Rational r;
		r.set_counter(a.get_counter() * b.get_counter());
		r.set_namer(a.get_namer() * b.get_namer());

		return r;
	}

	double rat_to_double(Rational r)
	{
		double d = r.get_counter() ;
		double d2 = r.get_namer();
		double d3 = d / d2;
		return d3;
	}

}