#include "doc.h"

int main()
{
	Document document = Document();
	read_data(document);
	replace_string("wie","Test", document);
	print(document);

	cout << "Count of Signs = " << count_char(document) << "\n";
	cout << "Count of Words = " << count_words(document) << "\n";
	cout << "Count of Alpha_Words = " << count_alpha_words(document) << "\n";
	char cc; cin >> cc;
}