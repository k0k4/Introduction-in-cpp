#include <string>
#include <iostream>
using namespace std;

struct God
{
	string name, mythologie, waffe, fahrzeug;
	God(string n, string m, string w, string f)
		:name(n), mythologie(m), waffe(w), fahrzeug(f) {}
};

template <class T>class Link
{
public:

	T val;
	Link(T t, Link<T>* p = 0, Link<T>* s = 0)
		:val(t), prev(p), succ(s) {}

	Link<T>* insert(Link<T>* n);

	Link<T>* next() { return succ; }
	Link<T>* previous() { return prev; }

private:
	Link<T>* prev;
	Link<T>* succ;
};


