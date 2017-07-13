// Übung7.1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"


/*
calculator08buggy.cpp

Die Kommentare wurden entfernt.

Wir haben 3 Fehler eingefügt, die der Compiler finden wird,
und drei Fehler, die Sie ohne seine Hilfe finden müssen
*/

using namespace std;

void error(string s)
{
	throw runtime_error(s);
}
								// Error Funktionen zum werfen einer Ausnahme falls ein fehler auftritt
void error(string s,string n)
{
	throw runtime_error(s + n);
}
// Selbstdefinierter Datentyp zum Auwerten der Eingabe, Eingabedaten sind Token
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) {}
};

// Stream zum einlesen und zurückstellen der Token
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square = 'S';
const string declkey = "let";
const string wurzel = "wurzel";
//Funktion zum einlesen der Token
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case let:
	case quit:
	case square:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token(let);
			if (s == "quit") return Token(name);
			if (s == wurzel) return Token(square);
			return Token(name, s);
		}
		error("Ungueltiges Token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;


double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: nicht definierter Name", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	return d;
	}
	
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("Faktor erwartet");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("Division durch null");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("Deklaration ohne Name");
	string name = t.name;
	if (is_declared(name)) error(name, " doppelt deklariert");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= fehlt in der Deklaration von ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}


double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	case square:
	{
		double d = expression();
		double sqr = sqrt(d);
		return sqr;
	}
	default:
		ts.unget(t);
		return expression();
	}
}



const string prompt = "> ";
const string result = "= ";


void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		//clean_up_mess();
	}
}


int main()

try {
	names.push_back(Variable("k", 1000));

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "Ausnahme: " << e.what() << endl;
	char c;
	while (cin >> c&& c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}

