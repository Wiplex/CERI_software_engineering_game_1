#include "../headers/entite.h"

#ifndef MONSTRE_H
#define MONSTRE_H
#pragma once

class monstre : public entite
{

public:
	//! Constructeur vide
	/*
		Crée un monstre vide.
		\warning Le monstre sera vide. Cela signifie qu'il ne sera pas utilisable pour le jeu, sa vie étant égale à 0
		\post Le monstre crée aura les paramètres suivants:
		- name = "Inconnu"
		- hpMax = 0
		- hpCurrent = 0
		- speed = 0
		- alive = true (sera changé immédiatement en false)
		- skillVect = <vecteur vide>
	*/
	monstre():entite(){};


	//! Constructeur avec tout
	/*!
		\param id L'identifiant du monstre
		\param name Le nom du monstre
		\param hpMax Les points de vie max du monstre
		\param speed La vitesse du monstre
		\param manaMax Les points de mana max du monstre
		\param description La description du monstre
		\param allSkills Un vecteur (std::vector) contenant toutes les compétences de ce monstre.
	*/
	monstre(std::string id, std::string name, int hpMax, int speed, int manaMax, std::string description, std::vector<competence> allSkills) : entite(id, name, hpMax, speed, manaMax, description, allSkills ){};


	//! Pour tester
	void printMonstre();


};


#endif // MONSTRE_H
