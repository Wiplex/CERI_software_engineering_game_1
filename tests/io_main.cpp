#include <iostream>
#include "../headers/io.h"
#include <stdio.h>

using namespace std;
using namespace io;

int main()
{
	cout << "Input de: ";
	char r = de();
	cout << endl << "Result de : " << r << endl;
	cout << "Result de : " << int(r) << endl;

	cout << "Input long : ";
	string s = long_input();
	cout << "Result : " << s << endl;

	cout << "Width : " << getTerminalWidth() << endl;
	cout << "Height : " << getTerminalHeight() << endl;

	// personnage test1("Bob", "un mec random");
	// personnage test2("Roger", "un autre mec random");

	// vector<personnage> vect_test;
	// vect_test.push_back(test1);
	// vect_test.push_back(test2);

	bienvenue();

	// personnage choisi = personnage();

 	// choisi = choix_unique_element(vect_test, true);

	return 0;
}
