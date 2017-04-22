#include <iostream>
#include <string>
#include <vector>

#ifndef CARTE_H
#define CARTE_H
#pragma once

class Carte
{
	std::string id;
	std::string nom ;
	std:: string description;
	int taille ;
	std::string ** plateau ;
	int nbr_monstre;
	int case_dispo;

	public:
		Carte();
		Carte(int taille, std::string name, std::string description) ;
		void verif_taille(int size);
		void coordonneejoueur();
		void coordonneeobstacle();
		void coordonneemonstre();
		void affichage_normal();
		//void affichage() ;
		int nbLigneFichier(std::string nomFichier);
		void sauvegarde() ;
		std::string getName() ;
		std::string getDescription() ;
		//bool carte_existe(std::string nom) ;
		//int quel_taille(std::string nom);
		//void suppression(std::string nom);
		static std::vector<Carte> chargement ();	///A déplacer dans fonctionsjeu.h
		Carte operator=(const Carte & a_copier);

};

#endif
