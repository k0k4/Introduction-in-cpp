// ÜbungTaschenrechner.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"



//
// Dieser Beispielcode stammt aus Kapitel 6.6 "Die erste Version ausprobieren" des Buches
// "Einführung in die Programmierung mit C++" von Bjarne Stroustrup
//

using namespace std;

//------------------------------------------------------------------------------

void error(string s)
{
	throw runtime_error(s);
}

//
// Dieser Beispielcode stammt aus dem Aufgabenteil von Kapitel 6 des Buches
// "Einführung in die Programmierung mit C++" von Bjarne Stroustrup
//

/*
Diese Datei heißt calculator02buggy.cpp

Ich habe 5 Fehler eingefügt, die korrigiert werden müssen, damit sich das Programm kompilieren lässt
Ich habe 3 logische Fehler eingefügt, die zu falschen Ergebnissen führen sollten

Versuchen Sie zunächst, die Fehler ohne Zuhilfenahme des Buches zu finden.
Wenn dies zu mühsam wird, vergleichen Sie den Code mit dem Code im Buch (oder der Beispielsammlung)

Fröhliche Jagd!

*/


//------------------------------------------------------------------------------
const char number = '8';

class Token{
public:
	char kind;        // welche Kategorie von Token
	double value;     // für Zahlen: ein Wert  
	Token(char ch)    // erstelle ein Token aus einem char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // erstelle ein Token aus einem char und einem double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();        // erstelle einen Token_stream, der aus cin liest 
	Token get();           // lies ein Token ein (get() ist anderswo definiert)
	void putback(Token t); // lege ein Token zurück 
private:
	bool full;    // befindet sich ein Token im Puffer?
	Token buffer; // hier legen wir ein Token ab, das mit putback() 
				  // zurückgestellt wurde
};


//------------------------------------------------------------------------------

// Der Konstruktor setzt full auf false, um anzuzeigen, dass der Puffer leer ist:
Token_stream::Token_stream()
	:full(false), buffer(0)    // kein Token im Puffer
{
}

//------------------------------------------------------------------------------

// Die Memberfunktion putback() stellt ihr Argument zurück in den Puffer von Token_stream:
void Token_stream::putback(Token t)
{
	if (full) error("putback(): Zurueckstellen nicht moeglich, Puffer voll");
	buffer = t;       // kopiere t in den Puffer
	full = true;      // Puffer ist jetzt voll
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {       // gibt es bereits ein fertiges Token?
					  // Token aus dem Puffer entfernen
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // beachten Sie, dass >> Whitespace-Zeichen wie 
				  // Leerzeichen, Zeilenumbruch, Tabulatorzeichen, etc. überspringt

	switch (ch) {
	case ';':   // für "Ausgeben"
	case 'q':    // für "Verlassen"
	case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}' : case '!' : case '%' :
		return Token(ch);        // jedes Zeichen repräsentiert sich selbst 
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // lege die Ziffer zurück in den Eingabestream
		double val;
		cin >> val;              // lies eine Gleitkommazahl 
		return Token(number, val);   // '8' repräsentiert "eine Zahl"
	}
	default:
		error("Ungueltiges Token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts;        // stellt get() und putback() zur Verfügung  

						//------------------------------------------------------------------------------

double expression();    // Deklaration, damit primary() expression() aufrufen kann

						//------------------------------------------------------------------------------

						// behandelt Zahlen und Klammern 
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '{':    // behandle'{' Ausdruck '}'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case '(':    // behandle'(' Ausdruck ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
			return d;
	}
	
	
	case number:            // wir verwenden '8' zur Repräsentation einer Zahl
		return t.value;  // liefere den Wert der Zahl zurück
	case '-':
		return -primary();
	case '+':
		return primary();

	default:
		error("Faktor erwartet");
	}
}

//------------------------------------------------------------------------------

// behandelt *, / und %

//Behandelt !
double faculty()
{
	double left = primary();
	Token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
		case '!':
		{
			int temp = 1;
			for (int i = 2; i <= left; i++)
			{
				temp *= i;
			}

			return temp;
		}

		default:
			ts.putback(t);
			return left;

		}
	}
}



double term()
{
	double left = faculty();
	Token t = ts.get();        // lies das nächste Token aus dem Token-Stream ein

	while (true) {
		switch (t.kind) {
		case '*':
			left *= faculty();
			t = ts.get();
			break;
		case '/':
		{
			double d = faculty();
			if (d == 0) error("Division durch null");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			int i1 = int(left);
			if (i1 != left) error("linker operand von % ist keine ganze Zahl");
			int i2 = int(d);
			if (i2 != d) error("rechter operand von % ist keine ganze Zahl");
			if (i2 == 0) error("%: Division durch null");
			left = i1 % i2;
			t = ts.get();
			break;
		}
		
		
		default:
			ts.putback(t);     // stelle t wieder zurück in den Token-Stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------



// behandelt + und –
double expression()
{
	double left = term();       // liest einen Token ein und wertet ihn aus
	Token t = ts.get();        // lies das nächste Token aus dem Token-Stream ein

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // werte Term aus und addiere
			t = ts.get();
			break;
		case '-':
			left -= term();    // werte Term aus und subtrahiere
			t = ts.get();
			break;
		default:
			ts.putback(t);     // stelle t wieder zurück in den Token-Stream
			return left;       // keine weiteren + oder –; Antwort zurückliefern
		}
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	
	cout << "Willkommen in unserem einfachen Taschenrechnerprogramm.\n Bitte geben Sie einen Ausdruck mit reelen Zahlen ein.\n";

	
	while (cin) {
		cout << "> ";
		Token t = ts.get();

		
		while (t.kind == ';') t = ts.get();        // '=' für "jetzt ausgeben"
		if (t.kind == 'q')
			return 0;
	
			ts.putback(t);
		cout << "=" << expression() << "\n";
	}
	
}
catch (exception& e) {
	cerr << "Fehler: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Hoppla: unbekannte Ausnahme!\n";
	return 2;
}

//------------------------------------------------------------------------------
