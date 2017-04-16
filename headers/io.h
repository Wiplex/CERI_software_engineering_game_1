#include <iostream>
using namespace std;

//! Cet espace sera un espace permettant de définir un buffer custom pour les input, ainsi que de pouvoir afficher tout ce que l'on souhaite.

namespace io
{
	std::istream io_input();
	extern char de();			// Demande l'entrée utilisateur
}
