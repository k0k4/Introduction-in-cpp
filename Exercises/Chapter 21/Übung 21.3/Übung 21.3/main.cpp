#include <iostream>
#include <vector>

template<class InputIt, class T>
int mycount(InputIt first, InputIt last,const T& val)
{
	int result = 0;
	for (; first != last; ++first)
		if (*first == val)
			result++;

	return result;
}

template<class InputIt, class UnaryPredicate>
int myCountIf(InputIt first, InputIt last, UnaryPredicate p)
{
	int result = 0;
	for (; first != last; ++first)
		if (p(*first))
			result++;

	return result;
}

int main()
{
	std::vector<int> v = { 1,2,3,2,4,5,6 };
	std::cout << "number of 2 = " << mycount(v.begin(), v.end(), 2) << "\n";
	std::cout << "number of %2 = " << myCountIf(v.begin(), v.end(), [](int i) {return i % 2 == 0; }) << "\n";
	char cc; std::cin >> cc;
}