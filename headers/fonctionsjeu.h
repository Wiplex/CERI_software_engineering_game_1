#include "../headers/io.h"
#include "../headers/carte.h"
#include "../headers/monstre.h"
#include "../headers/competence.h"
#include "../headers/personnage.h"
#include <stack>

#ifndef FONCTIONSJEU_H
#define FONCTIONSJEU_H
#pragma once

using namespace io;

//! Ceci sera la classe du jeu. Elle contient toutes les entités, la carte, ainsi que les fonctions nécessaires à la partie.
/*!
	Cette classe contient les fonctions nécessaires au démarrage de la partie, au combat, ainsi que toutes les fonctions intermédiaires nécessaires au bon fonctionnement de celles-ci.

	Librairies incluses :
		- std::stack ,
		- io ( depuis io.h )
*/
class jeu
{
	//! Carte du jeu, à choisir au début du jeu.
	Carte * jeu_carte;
	//! Personnage choisi par le joueur, à choisir au début du jeu.
	personnage * jeu_perso;
	// std::stack<> jeu_coups;
	//! Compte le nombre de monstres restant sur la carte.
	int jeu_nombre_monstre;

	public:
		//! Constructeur par défaut sans argument.
		/*!
			Avec ce constructeur, on peut créer toutes les entités du jeu.

			- Chargement de la carte,
			- Création d'un personnage,
			- Création de tous les monstres.

			\sa perso(), carte(), monstre()
		*/
		jeu();
		//! Destructeur par défaut.
		~jeu();
		//! Fonction permettant de déterminer comment va démarrer la partie.
		/*!
			Etant donné que cette fonction utilise des entités externes, il faut que tout le monde aie fini lesdites entités pour que la fonction compile.
		*/
		void demarrer_jeu();
	//	void combat(personnage *p, monstre *m);
	//	void application_coup(personnage *p, competence *a, monstre *m, competence *b);
};

#endif

/*!
	\mainpage The Game

	Bienvenue sur la documentation pour le projet de Génie Logiciel de l'année universitaire 2016/2017 de L2 Informatique. Ce projet à été réalisé par le groupe des Poussins. Le groupe est composé de :
	- Raphaël Montet
	- Ludivine Nouveau
	- Loïc Menguy
	- Malvina Gontard
	- Thibault de Villèle

	Le projet, dans son intégrité, peut être trouvé sur [GitHub](http://www.github.com/Thibaulltt/CERI_software_engineering_1/). Dans le dépôt, vous pourrez trouver le code, ansi que les données et recherches effectuées au préalable.

	Cette année, nous avons la tâche de réaliser un jeu de type RPG avec une interface CLI.
*/
