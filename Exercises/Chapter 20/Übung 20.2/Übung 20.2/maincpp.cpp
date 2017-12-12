#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double* get_from_jack(int* count)
{
	ifstream jack_file("jack_data.txt");
	double read = 0;
	double* buff = new double[20];
	while (jack_file >> read)
	{
		buff[*count] = read;
		*count += 1;
	}
	
	return buff;
}

vector<double>* get_from_jill()
{
	ifstream jill_file("jill_data.txt");
	double read = 0;
	vector<double>* buff = new vector<double>();
	while (jill_file >> read)
		buff->push_back(read);

	return buff;
}

double* high(double* first, double* last)
{
	
	double* high = first;
	for (double* p = first; p != last; ++p)
		if (*p > *high)
			high = p;
	return high;
}

void fct()
{
	int jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);
	vector<double>* jill_data = get_from_jill();

	double* jack_high = high(jack_data, jack_data + jack_count);
	vector<double>& v = *jill_data;
	double* jill_high = high(&v[0], &v[0] + v.size());

	cout << "jacks maximum value == " << *jack_high << "\n"
		<< "jills maximum value == " << *jill_high;

	delete[] jack_data;
	delete jill_data;
}

int main()
{
	fct();
	char cc; cin >> cc;
}