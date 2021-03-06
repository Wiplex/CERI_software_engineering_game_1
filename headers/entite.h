#include <string>
#include <vector>
#include "competence.h"

#ifndef ENTITE_H
#define ENTITE_H


class entite
{
protected:
	std::string entiteId;
	std::string entiteName;
	std::string entiteDescription;
	int entiteHpMax;
	int entiteHpCurrent;
	int entiteManaMax;
	int entiteManaCurrent;
	int entiteSpeed;
	bool entiteAlive;
	std::vector<competence> entiteSkillVect;

public:
	//! Constructeur vide
	/*
		Crée une entité vide.
		\warning L'entité sera vide. Cela signifie qu'elle ne sera pas utilisable pour le jeu, sa vie étant égale à 0
		\post L'entite crée aura les paramètres suivants:
		- entiteName = "Inconnu"
		- entiteHpMax = 0
		- entiteHpCurrent = 0
		- entiteSpeed = 0
		- entiteAlive = true (sera changé immédiatement en false)
		- entiteSkillVect = <vecteur vide>
	*/
	entite();

	//! Constructeur avec tout
	/*!
		\param entiteId L'identifiant de l'entite
		\param entiteName Le nom de l'entite
		\param entiteHpMax Les points de vie max de l'entite
		\param entiteSpeed La vitesse de l'entite
		\param entiteManaMax Les points de mana max de l'entite
		\param entiteDescription La description de l'entite
		\param allSkills Un vecteur (std::vector) contenant toutes les compétences de cette entite.
	*/
	entite(std::string entiteId, std::string entiteName, int entiteHpMax, int entiteSpeed, int entiteManaMax,std::string entiteDescription, std::vector<competence> allSkills);

	template<typename T> std::string toString(const T & valeur); // Conversion de n'importe quoi en string

	//!Getter pour l'id.
	std::string getID();

	//! Getter pour le nom.
	std::string getName();

	//! Getter pour la description.
	std::string getDescription();

	//! Getter pour le nombre de points de vie max.
	int getHpMax();

	//! Getter pour le nombre de points de vie actuels.
	int getHpCurrent();

	//! Getter pour la vitesse d'attaque de l'entite.
	int getSpeed();

	//! Getter qui permet de savoir si l'entite est en vie.
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
		- entiteIdentifiant (type <code>m\<entier></code>)
		- nom de l'entite
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

	//! Permet d'écrire l'entite dans un fichier de sauvegarde
	void saveInFile(std::string lettreEntite, std::string nomFichier);

	//! Identification personnage
	bool is_personnage();

	//! Affichage en détail
	void afficher_detail();

	//! Affichage en combat
	/*!
		Permet de limiter l'affichage d'une entité à ses caractéristiques utiles en combat
	*/
	void afficher_combat();

	//! Enlève x points de vie a l'entite.
	/*!
		Cette fonction permet d'enlever des points de vie. Elle permet aussi de savoir si une entite est en vie (ptsVie < 0) ou si elle est morte.
		\return Un booléen qui est égal à <code>true</code> si le entite est mort, <code>false</code> sinon.
	*/
	entite enleverVie(int degats);

	//! Enlève x points de mana a l'entite.
	/*!
		Cette fonction ne sert à rien, à part ne pas faire bugger les autres.
		\return Un booléen vérifiant la capacité à dépenser la mana.
	*/
	bool enleverMana(int skillManaCost);


};

#endif // ENTITE_H
