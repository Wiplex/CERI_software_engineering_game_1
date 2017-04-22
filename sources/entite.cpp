#include "../headers/entite.h"
#include <iostream>
#include <fstream>

using namespace std;


// --------------------CONSTRUCTEURS

entite::entite()      //Constructeur vide
{
	this->id="";
	this->name = "Inconnu";
	this->description = "";
	this->hpMax = 0;
	this->hpCurrent = hpMax;
	this->manaMax = 0;
	this->manaCurrent = 0;
	this->speed = 0;
	this->alive = true;
	vector<competence> skillVect;
}


entite::entite(string id, string name, int hpMax, int speed, int manaMax, string description, std::vector<competence> allSkills) //Constructeur avec arguments de caractéristiques du entite
{
	this->id=id;
	this->name = name;
	this->description = "";
	this->hpMax = hpMax;
	this->hpCurrent = this->hpMax;
	this->manaMax = manaMax;
	this->manaCurrent = manaMax;
	this->speed = speed;
	this->alive = true;
	vector<competence> skillVect = allSkills;
}


//-------------------------------------------FONCTIONS


template<typename T>string entite::toString( const T & valeur ) //Conversion de n'importe quoi en string
{
	ostringstream flux;
	flux << valeur;
	return flux.str();
}


//-----GET ATTRIBUTS

string entite::getId() //Rretourne l'id d'une entite
{
	return this->id;
}


string entite::getName() //Retourne le nom d'une entite
{
	return this->name;
}


string entite::getDescription() //Retourne la description d'une entite
{
	return this->description;
}


int entite::getHpMax() //Retourne le nombre de points de vie max d'une entite
{
	return this->hpMax;
}


int entite::getHpCurrent() //Retourne le nombre de points de vie actuel d'une entite
{
	return this->hpCurrent;
}


int entite::getManaMax() //Retourne les points de mana MAX d'une entite
{
	return this->manaMax;
}

int entite::getManaCurrent() //Retourne les points de mana actuel d'une entite
{
	return this->manaCurrent;
}


int entite::getSpeed() //Retourne la vitesse d'une entite
{
	return this->speed;
}


bool entite::getAlive() //Retourne l'�tat de vie ou de mort d'un entite
{
	return this->alive;
}


vector<competence> entite::getSkillVect() //Retourne le vecteur de compétence d'un entite
{
	return this->skillVect;
}


// POUR SAUVEGARDE DANS FICHIER


int entite::nbLigneFichier(string nomFichier) //Compte le nb de ligne du fichier pour créer l'identifiant unique d'un entite
{
	ifstream fichier(nomFichier.c_str()); //Ouverture en mode lecture
	int nbLigne = 0;
	if(fichier)
	{
		string ligne="";

		while(getline(fichier, ligne)) //Stockage de chaque ligne du fichier
		{
			nbLigne++;
		}
		fichier.close(); //On ferme le fichier
	}

	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}

	return nbLigne;
}


string entite::entiteString(string lettreEntite, string nomFichier) //Convertit toutes les caracs. d'un entite en string
{
	string ligneFichier;

	int nbEntite = this->nbLigneFichier(nomFichier.c_str());
	string sNbEntite;
	sNbEntite = toString(nbEntite);

	string ID;
	ID = lettreEntite + sNbEntite;

	string sHpMax;
	sHpMax = toString(this->hpMax);

	string sSpeed;
	sSpeed = toString(this->speed);

	string sManaMax;
	sManaMax = toString(this->manaMax);

	string allSkill="";
	for (int i=0 ; i< skillVect.size() ; i++) //Conversion de toutes les compétences en une ligne de string
	{
		allSkill += skillVect[i].competenceString() + ":";
	}

		ligneFichier = ID + "/" + this->name + "/" + sHpMax + "/" + sSpeed + "/" + allSkill + "|" + sManaMax + "|" + this->description + '\n'; //Création de la ligne compléte


	return ligneFichier;
}


void entite::saveInFile(string lettreEntite,string nomFichier) //Ecrit les carac d'un entite dans un fichier
{
	ofstream fichierentite(nomFichier.c_str(), ios::out | ios::app); // Ouverture du fichier en écriture, avec curseur en fin de fichier.

	string entiteLigne = this->entiteString(lettreEntite, nomFichier);

	if(fichierentite) //Vérification ouverture du fichier
	{
		fichierentite << entiteLigne; //Ecriture de la ligne
		fichierentite.close();
	}

	else
	{
		cerr << "Impossible d'ouvrir le fichier." << endl;
	}
}


// FONCTIONS


bool entite::enleverVie(int degats)
{
	this->hpCurrent-=degats;

	if(this->hpCurrent <= 0)
	{
		this->alive = false;
		return true; //Si mort, return true
	}
	return false;
}

///Problème ici, si la dépense de mana n'est pas possible, la mana est quand même dépensée.
///De même, <= 0 empêche d'utiliser les compétences qui utilisent exactement le bon montant de mana.
bool entite::enleverMana(int manaCost)
{
	if (this->manaCurrent>= manaCost)
	{
		this->manaCurrent -= manaCost;
		return true;
	}

	if(this->manaCurrent < manaCost)
	{
		return false;
	}
}


// TESTS


void entite::printEntite()
{
	cout << "nom : " << this->name<< endl;
	cout << "hp max : " << this->hpMax<< endl;
	cout << "speed : " << this->speed<< endl;

	for (int i=0 ; i<this->skillVect.size() ; i++)
	{
		this->skillVect[i].printCompetence();
	}

	cout << endl;
}
