#include "monstre.h"
#include "personnage.h"

#ifndef INTERFACE_H
#define INTERFACE_H

struct interface
{
	//! Vérifie que l'user entre des entier
	/*!
		Cette fonction vérifie que l'entrée utilisateur est bien un entier.

		Mode opératoire :
		- Vérification du failbit de l'entrée utilisateur (std::cin::failbit)
			-# Vidage du buffer
			-# Ignore 256 caractères ou jusqu'a <pre>\n</pre>
			-# Affichage d'un message d'erreur d'entrée utilisateur.
			-# Retourne faux
		- Sinon retourne vrai
		\param x on sait pas ce qu'il fait la, mais il est la.
	*/
	bool checkInput(int x);
	//! Creer une competence
	/*!
		Cette fonction permet de créer rapidement une compétence pour pouvoir l'utiliser facilement après.

		Mode opératoire :
		- On crée les variables qui vont tenir les infos rentrées (skillName, damage, manaCost)
		- On rentre
	*/
	competence createCompetence();
	//! Créer une compétence pour monstre (sans mana)
	competence createCompetenceMonstre();
	//Créer un monstre
	monstre createMonstre();
	//! Récupérer les compétences d'un monstre dans le .txt
	std::vector<competence> loadCompetenceFromFile(std::string nomFichier,int numLigne);

	//Retourne un vecteur contenant tous les monstres du fichier .txt
	std::vector<monstre> loadAllMonstreFromFile();
	//! Retourne un vecteur contenant tous les personnages du fichier .txt
	std::vector<personnage> loadAllPersonnageFromFile();

	//! Retourne un monstre aléatoire parmi un vecteur de monstre
    monstre randomMonstre(vector<monstre> allMonstre);
};

#endif
