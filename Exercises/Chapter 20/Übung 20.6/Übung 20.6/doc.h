#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

typedef vector<char> Line;

class Text_iterator
{
	list<Line>::iterator ln;
	Line::iterator pos;
public:
	Text_iterator(list<Line>::iterator ll, Line::iterator pp)
		:ln(ll),pos(pp){}

	char& operator*() { return *pos; }
	Text_iterator& operator++();

	bool operator==(const Text_iterator& other) const
	{ return ln == other.ln && pos == other.pos; }
	bool operator!=(const Text_iterator& other) const
	{ return !(*this == other); }
	Line::iterator get_pos() { return pos; }
	list<Line>::iterator get_line() { return ln; }
	void set(Line::iterator p) { pos = p; }
};

Text_iterator& Text_iterator::operator++()
{
	++pos;
	if (pos == (*ln).end())
	{
		++ln;
		pos = (*ln).begin();
	}

	return *this;
}

struct Document
{
	list<Line> line;

	Document() { line.push_back(Line()); }
	Text_iterator begin() { return Text_iterator(line.begin(), (*line.begin()).begin()); }
	Text_iterator end() 
	{
		list<Line>::iterator last = line.end();
		--last;
		return Text_iterator(last, (*last).end());
	}
};

istream& operator>>(istream& is, Document& d)
{
	char ch;
	while (is.get(ch))
	{
		d.line.back().push_back(ch);
		if (ch == '\n')
			d.line.push_back(Line());
	}
	if (d.line.back().size())
		d.line.push_back(Line());
	return is;
}

void print(Document& d)
{
	for (Text_iterator p = d.begin(); p != d.end(); ++p) cout << *p;
	cout << "\n";
}

void read_data(Document& dd)
{
	ifstream ist("docu.txt");
	ist >> dd;
}
template<class iter>
bool match(iter p, iter last, string s)
{
	
	for (int i = 0; i < s.size(); i++)
	{
		if (*p != s[i] || p == last)
			return false;
		else
			++p;
	}
	return true;
}

Text_iterator find_char(Text_iterator first, Text_iterator last, char c)
{
	while (first != last && *first != c) ++first;
		return first;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
	if (s.size() == 0)
		return last;
	char first_char = s[0];
	while (true)
	{
		Text_iterator p = find_char(first, last, first_char);
		if (p == last || match(p, last, s)) return p;
		++first;
	}
	
}

void replace_string(string s, string ns,Document& d)
{
	Text_iterator p = find_txt(d.begin(), d.end(), s);
	if (p == d.end())
		cout << "not found :(\n";
	else
	{
		p.set(p.get_line()->erase(p.get_pos(), p.get_pos() + s.size()));
		p.get_line()->insert(p.get_pos() , ns.begin(), ns.end());
	}
}

int count_char(Document& d)
{
	int count = 0;
	Text_iterator p = d.begin();
	for (Text_iterator p = d.begin(); p != d.end(); ++p)
		if (isprint(*p))
			count++;
	return count;
}

int count_words(Document& d)
{
	int count = 0;
	Text_iterator p = d.begin();
	for (Text_iterator p = d.begin(); p != d.end(); ++p)
		if (isspace(*p))
			count++;
	return count;

}

int count_alpha_words(Document& d)
{
	int count = 0;
	Text_iterator p = d.begin();
	while (p != d.end())
	{
		if (isalpha(*p))
		{
			count++;
			while (p != d.end() && isalpha(*p))
				++p;
		}
		else
			++p;
	}
	return count;
}

