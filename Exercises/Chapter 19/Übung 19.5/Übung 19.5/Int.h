#include <iostream>
using namespace std;

template<class T>class Number
{
	T val;

public:
	Number(T i)
		:val(i) {}

	T get() const { return val; }
	void set(T a) { val = a; }
	T& operator=(const T& a);

	
	Number& operator=(const Number& a);

};

template<class T>
T& Number<T>::operator=(const T& a)
{
	if (this == &t) return *this;
	val = a;
	return *this;
}

template<class T>
Number<T>& Number<T>::operator=(const Number<T>& a)
{
	if (this == &a) return *this;
	val = a.get();
	return *this;
}

template<class T>
Number<T> operator+(Number<T> a, Number<T> b)
{
	Number<T> t(0);
	t.set(a.get() + b.get());
	return t;
}
template<class T>
Number<T> operator-(Number<T> a, Number<T> b)
{
	Number<T> t(0);
	t.set(a.get() - b.get());
	return t;
}

template<class T>
Number<T> operator*(Number<T> a, Number<T> b)
{
	Number<T> t(0);
	t.set(a.get() * b.get());
	return t;
}

template<class T>
Number<T> operator/(Number<T> a, Number<T> b)
{
	Number<T> t(0);
	t.set(a.get() / b.get());
	return t;
}

template<class T>
ostream& operator<<(ostream& os, Number<T> a)
{
	os << a.get();
	return os;
}









