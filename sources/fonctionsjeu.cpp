#include "../headers/fonctionsjeu.h"
#include <iostream>	// à remplacer avec notre librairie I/O plus tard

jeu::jeu()
{
	jeu_perso = new personnage();		// À COMPLÉTER UNE FOIS QUE CLASSE PERSO FINIE
	jeu_carte = new Carte();			// À COMPLÉTER UNE FOIS QUE CLASSE CARTE FINIE
	jeu_nombre_monstre = 8;				// À COMPLÉTER UNE FOIS QUE CLASSE CARTE FINIE
	// Normalement, à ca point là, la carte doit être chargée, le personnage est choisi et chargé, les monstres sont chargés et il ne reste qu'à lancer le jeu.
}

jeu::~jeu()
{}

void jeu::demarrer_jeu()
{
	bienvenue();



	// custom_buffer.affichercarte(jeu_carte);
}

bool sort_speed(entite a, entite b)
{
	return a.getSpeed() < b.getSpeed();
}
