#include "../headers/fonctionsjeu.h"
#include "../headers/io.h"
#include <iostream>	// à remplacer avec notre librairie I/O plus tard

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

void jeu::combat(perso &p, monstre &m)
{
	while (monstre_mort == 0)
	{
		v_retour a = choisir_coup(player);
		v_retour b = choisir_coup(monster);
		application_coup(p,a,m,b);
		if (joueur_mort == 1)
			fin_de_partie();
	}
}
