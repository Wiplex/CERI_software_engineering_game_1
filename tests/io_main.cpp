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

	return 0;
}
