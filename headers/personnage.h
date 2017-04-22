#include "../headers/entite.h"

#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#pragma once

class personnage : public entite //Classe personnage héritant de la classe monstre
{

public:

	//! Constructeur vide
	/*!
		Le personnage créé aura 0 de mana, et n'aura aucune description. Mais il sera crée.
	*/
	personnage():entite()
	{
	};


	personnage(std::string id, std::string name, int hpMax, int speed, int manaMax, std::string description, std::vector<competence> allSkills) : entite(id, name, hpMax, speed, manaMax, description, allSkills )
	{
	};


	//! Getter pour la mana maximum du personnage
	int getManaMax();
	//! Getter pour la mana actuelle du personnage
	int getManaCurrent();
	//! Getter pour la description du personnage
	std::string getDescription();

	//! Convertit toutes les caracs. d'un personnage en string
	std::string personnageString();
	//! Ecrit toutes les carac. d'un perso dans un fichier
	void savePersoInFile();

	//! Return true si le personnage a toujours du mana
	bool enleverMana(int manaCost);

	//! Fonction de test
	void printPersonnage();
};

#endif
