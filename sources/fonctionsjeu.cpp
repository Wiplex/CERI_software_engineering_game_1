#include "../headers/fonctionsjeu.h"
#include <iostream>	// à remplacer avec notre librairie I/O plus tard
#include "./io.h"

using namespace io;
using namespace std;

jeu::jeu()
{
	// jeu_perso = new perso();			// À COMPLÉTER UNE FOIS QUE CLASSE PERSO FINIE
	// jeu_carte = new carte();			// À COMPLÉTER UNE FOIS QUE CLASSE CARTE FINIE
	// jeu_nombre_monstre = carte.getMonsters();	// À COMPLÉTER UNE FOIS QUE CLASSE CARTE FINIE
}

jeu::~jeu()
{}

void jeu::demarrer_jeu()
{
	Bienvenue();
	cout << "Bienvenue dans le jeu" << endl;
	// custom_buffer.affichercarte(jeu_carte);
}
