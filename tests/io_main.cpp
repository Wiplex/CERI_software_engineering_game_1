#include <iostream>
#include "../headers/io.h"

using namespace std;
using namespace io;

int main()
{
    Bienvenue();

    cout << "Input de: ";
	char r = de();
	cout << "Result de : " << r << endl;

	Bienvenue();

	test test1("Bob", "un mec random");
	test test2("Roger", "un autre mec random");

    vector<test> vect_test;
    vect_test.push_back(test1);
    vect_test.push_back(test2);

    afficher(test1, 1);

    cout << endl;

    choix_element(vect_test, 1);

	return 0;
}
