#include <iostream>
#include "../headers/io.h"
#include <stdio.h>

using namespace std;
using namespace io;

int main()
{
	cout << "Test " << BLUE << "io::" << MAGENTA << "de()" << BLANK << " : ";
	char r = de();
	cout << endl << "Resultat " << BLUE << "io::" << MAGENTA << "de()" << BLANK << " : " << r << endl;
	cout << "Resultat " << YELLOW << "int" << BLANK << "( " << BLUE << "io::" << MAGENTA << "de()" << BLANK << " ) : " << int(r) << endl;

	cout << "Test " << BLUE << "io::" << MAGENTA << "long_input()" << BLANK << " : ";
	string s = long_input();
	cout << "Resultat : " << s << endl;

	cout << "Test " << BLUE << "io::" << MAGENTA << "getTerminalWidth()" << BLANK << " : " << getTerminalWidth() << endl;
	cout << "Test " << BLUE << "io::" << MAGENTA << "getTerminalHeight()" << BLANK << " : " << getTerminalHeight() << endl;
	cout << "Test " << BLUE << "io::" << RED << "TermWidth" << BLANK << " : " << io::TermWidth << endl;
	cout << "Test " << BLUE << "io::" << RED << "TermWidth" << BLANK << " : " << io::TermHeight << endl;

	cout << "Test " << BLUE << "io::" << MAGENTA << "afficherInteractions()" << BLANK << " : " << endl;
	afficherMouvements();
	de();
	afficherMouvements("Désolé, cette case est inaccessible car vous êtes cons !");

	return 0;
}
