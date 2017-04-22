#include <string>
#include <vector>
#include "competence.h"

#ifndef ENTITE_H
#define ENTITE_H


class entite
{
protected:
	std::string id;
	std::string name;
	std::string description;
	int hpMax;
	int hpCurrent;
	int manaMax;
	int manaCurrent;
	int speed;
	bool alive;
	std::vector<competence> skillVect;

public:
	//! Constructeur vide
	/*
		Crée un entite vide.
		\warning Le entite sera vide. Cela signifie qu'il ne sera pas utilisable pour le jeu, sa vie étant égale à 0
		\post Le entite crée aura les paramètres suivants:
		- name = "Inconnu"
		- hpMax = 0
		- hpCurrent = 0
		- speed = 0
		- alive = true (sera changé immédiatement en false)
		- skillVect = <vecteur vide>
	*/
	entite();

	//! Constructeur avec tout
	/*!
		\param id L'identifiant de l'entite
		\param name Le nom de l'entite
		\param hpMax Les points de vie max de l'entite
		\param speed La vitesse de l'entite
		\param manaMax Les points de mana max de l'entite
		\param description La description de l'entite
		\param allSkills Un vecteur (std::vector) contenant toutes les compétences de cette entite.
	*/
	entite(std::string id, std::string name, int hpMax, int speed, int manaMax,std::string description, std::vector<competence> allSkills);




	template<typename T> std::string toString(const T & valeur); // Conversion de n'importe quoi en string

	//!Getter pour l'ID.
	std::string getId();

	//! Getter pour le nom.
	std::string getName();

	//! Getter pour la description.
	std::string getDescription();

	//! Getter pour le nombre de points de vie max.
	int getHpMax();

	//! Getter pour le nombre de points de vie actuels.
	int getHpCurrent();

	//! Getter pour la vitesse d'attaque du entite.
	int getSpeed();

	//! Getter qui permet de savoir si le entite est en vie.
	bool getAlive();

	//! Getter pour la mana maximum de l'entite
	int getManaMax();

	//! Getter pour la mana actuelle de l'entite
	int getManaCurrent();

	//! Getter qui renvoie un vecteur (std::vector) de compétences.
	std::vector<competence> getSkillVect();

	//! Retour d'une string représentant un entite.
	/*!
		Convertit un objet entite en une ligne de string.
		\post La string contiendra les infos dans cet ordre :
		- identifiant (type <code>m\<entier></code>)
		- nom du entite
		- nombre de points de vie
		- vitesse d'attaque
		- toutes les compétences , séparées par des <code>:</code>
	*/

	//! Retourne le nombre de lignes d'un fichier.
	/*!
		Compte le nb de lignes du fichier pour créer l'identifiant unique d'un entite. L'identifiant sera <code> nbLignes + 1 </code>
		\return Un entier représentant le nombre de lignes.
		\param nomFichier Une string (std::string) qui sera le nom du fichier à ouvrir.
	*/
	int nbLigneFichier(std::string nomFichier);

	std::string entiteString(std::string lettreEntite, std::string nomFichier);

	//! Permet d'écrire le entite dans un fichier de sauvegarde
	void saveInFile(std::string lettreEntite, std::string nomFichier);

	//! Pour tester
	void printEntite();

	//! Enlève x points de vie au entite.
	/*!
		Cette fonction permet d'enlever des points de vie. Elle permet aussi de savoir si un entite est en vie (ptsVie < 0) ou si il est mort.
		\return Un booléen qui est égal à <code>true</code> si le entite est mort, <code>false</code> sinon.
	*/
	bool enleverVie(int degats);

	//! Enlève x points de mana au entite.
	/*!
		Cette fonction ne sert à rien, à part ne pas faire bugger les autres.
		\return Un booléen vérifiant la capacité à dépenser la mana.
	*/
	bool enleverMana(int manaCost);


};

#endif // ENTITE_H
