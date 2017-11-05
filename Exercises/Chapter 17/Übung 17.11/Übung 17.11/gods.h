#include <string>
#include <iostream>
using namespace std;

struct God
{
	string name, mythologie, waffe, fahrzeug;
	God(string n, string m, string w, string f)
		:name(n), mythologie(m), waffe(w), fahrzeug(f) {}
};

class Link
{
public:
	
	God god;
	Link(God g, Link* p = 0, Link* s = 0)
		:god(g), prev(p), succ(s){}

	Link* insert(Link* n);

	Link* next() { return succ; }
	Link* previous() { return prev; }

private:
	Link* prev;
	Link* succ;
};


void print_gods(Link* g);

