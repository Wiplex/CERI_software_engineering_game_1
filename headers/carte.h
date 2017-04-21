#include <iostream>
#include <string>

#ifndef CARTE_H
#define CARTE_H

class Carte
{
	std::string nom ;
	std:: string description;
	int taille ;
	char ** plateau ;
	public:
		Carte();
		Carte(int taille, std::string name, std::string description) ;
		void affichage() ;
		void sauvegarde() ;
		std::string getName() ;
		std::string getDescription() ;
		bool carte_existe(std::string nom) ;
		void chargement (std::string nom_selection);
		int quel_taille(std::string nom);
		void suppression(std::string nom);
};

#endif
