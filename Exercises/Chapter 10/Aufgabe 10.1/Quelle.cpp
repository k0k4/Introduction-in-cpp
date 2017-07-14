#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;
// simple point structure
struct Point
{
	int x, y;
	Point()
		: x(0), y(0) {}
};
//define output operator for points
ostream& operator<<(ostream& os, const Point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}
//define input operator for points
//liest den punkt von is nach p ein
// Format (1,2)
istream& operator >> (istream& is, Point& p)

{
	char ch1;
	if (is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2, ch3;
	int x, y;
	is >> x >> ch2 >> y >> ch3;
	//if (!is || ch2 != ',' || ch3 != ')') cout << "Error: invalid read\n";
	p.x = x;
	p.y = y;
	return is;
}
//read a point and save into vector
void read_point(vector<Point>& p)
{
	Point ptemp = Point();

	cout << "Please insert x coordinate >> ";
	cin >> ptemp.x;
	cout << "Please insert y coordinate >> ";
	cin >> ptemp.y;
	p.push_back(ptemp);
}
//function to write a point vector into a .txt file
void write_in_txt(const vector<Point>& p, ofstream& ofs)
{
	for (int i = 0; i < p.size(); i++)
		ofs << p[i] << "\n";
}


//function to read out of a .txt file
void read_out_file(vector<Point>& p, ifstream& istr)
{
	while (true)
	{
		Point ptemp;
		if (!(istr >> ptemp)) break;
		p.push_back(ptemp);
	}
	
}

void main()
{
	vector<Point>points;
	vector<Point>processed_points;
	string fileName = ".\\myData.txt";
	
	ofstream ostr(fileName.c_str());
	if (!ostr) cout << "can't open file\n";
	
	for (int i = 0; i < 7; i++)
	read_point(points);
	
	write_in_txt(points, ostr);
	
	ostr.close();

	ifstream istr(fileName.c_str());
	if (!istr) cout << "can't open file\n";
	read_out_file(processed_points, istr);
	
	for (int i = 0; i < processed_points.size(); i++)
		cout << processed_points[i] << "\n";

	char cc; cin >> cc;
}