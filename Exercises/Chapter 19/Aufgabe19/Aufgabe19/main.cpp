#include <vector>
#include <iostream>

using namespace std;

template<class T> struct S
{
	T val;

	S(T t)
		:val(t){ }
	
	T& get();
	T& operator=(const T&);
};

template<class T> T& S<T>::get()
{
	return this->val;
}

template<class T> T& S<T>::operator=(const T& t)
{
	if (this == &t) return *this;
	
	val = t;
	
	return *this;

}

template<class T> void read_val(T& v)
{
	cout << ">>";
	cin >> v;
}

int main()
{
	
	S<int> a(1);
	S<double> b(2.1);
	S<char> c('c');
	S<vector<int>> d(vector<int>(0));
	S<int> g(3);
	


	d.val.push_back(2);
	d.val.push_back(3);
	
	cout << "a = " << a.val << "\nb = " << b.val << "\nc = " << c.val << "\nd1 = " << d.val[0] << "\nd2  = " << d.val[1] << "\n";

	

	char cc; cin >> cc;

}