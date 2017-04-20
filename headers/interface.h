#include "monstre.h"
#include "personnage.h"
#ifndef INTERFACE_H
#define INTERFACE_H

struct interface
{
	bool checkInput(int x); //V�rifie que l'user entre des entier
	competence createCompetence(); //Creer une competence
	competence createCompetenceMonstre(); //Cr�er une comp�tence pour monstre (sans mana)
	monstre createMonstre(); //Cr�er un monstre
	vector<competence> loadCompetenceFromFile(string nomFichier,int numLigne); //R�cup�rer les comp�tences d'un monstre dans le .txt

	vector<monstre> loadAllMonstreFromFile(); //Retourne un vecteur contenant tous les monstres du fichier .txt
	vector<personnage> loadAllPersonnageFromFile();
};

#endif
