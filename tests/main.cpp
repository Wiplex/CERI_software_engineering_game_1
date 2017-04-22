#include "../headers/fonctionsjeu.h"
#include "../headers/carte.h"
#include "../headers/interface.h"
#include "../headers/io.h"
#include <algorithm>
#include <iostream>

using namespace io;
using namespace std;

int main()
{
	//Phase préparation partie
	jeu a;
	a.demarrer_jeu();

		//Choix personnage
	vector<personnage> tous_persos;
	tous_persos = loadAllPersonnageFromFile();

	personnage perso_jeu = personnage();
	perso_jeu = choix_unique_element(tous_persos);

		//Choix carte
	vector<Carte> toutes_cartes;

	Carte carte;

	toutes_cartes = carte.chargement();	//Core dump pour l'instant (22/04, 01:04)
	cout << "test taille vecteur map: " << toutes_cartes.size();

	Carte map_jeu = choix_unique_element(toutes_cartes);

	choix_unique_element(toutes_cartes).affichage_normal();
	map_jeu.affichage_normal();

		//Chargement monstres
	vector<monstre> monstres_jeu;
	vector<monstre>::iterator itm;

	monstres_jeu = loadAllMonstreFromFile();

//	for (itm = monstres_jeu.begin(); itm != monstres_jeu.end(); itm++)
//	{
//        itm -> printMonstre();
//	}

//		//Combat (création pile, tri acteurs, empilage, application compétences, dépilage).

	vector<monstre> vect_entite;
	vector<monstre>::iterator ite;
	vector<monstre>::iterator death;

	vect_entite.push_back(perso_jeu);
	vect_entite.push_back(monstres_jeu[0]);
//
	sort(vect_entite.begin(), vect_entite.end(), sort_speed);

	vector<int> vect_p;

//	for (int i = 0; i < vect_entite.size(); i++)		//Identification acteurs personnages
//	{
//		if (vect_entite[i].getId().substr(1,1) == "p")	//Si Id personnage
//		{
//			vect_p.push_back(i);						//Rajout indice personnage
//		}
//	}

	int nb_players = vect_p.size();						//Nombre personnages
	int nb_monsters = vect_entite.size() - nb_players;	//Nombre monstres


//	while (1)
//	{
//		competence comp_util;
//		monstre target;
//
//		for (ite = vect_entite.begin(); ite != vect_entite.end(); ite++)
//		{
//			if ((* ite).getId().substr(1, 1) == "p")			//Si personnage (choix manuel compétence)
//			{
//				choix:
//				comp_util = choix_unique_element((* ite).getSkillVect());
//			}
//			else												//Si monstre (choix aléatoire compétence)
//			{
//				comp_util = (* ite).getSkillVect()[rand() % (* ite).getSkillVect().size()];
//			}
//
//			if (!(* ite).enleverMana(comp_util.getManaCost()))	//Mana insuffisant pour lancer compétence
//			{
//				cout << "Vous n'avez pas assez de mana pour utiliser cette compétence!";
//				cout << "Choisissez-en une autre!";
//				goto choix;
//			}
//			else												//Mana suffisant pour lancer compétence
//			{
//					//Choix cible
//				if ((* ite).getId().substr(1, 1) == "p")		//Si personnage (choix manuel cible)
//				{
//                    target = choix_unique_element(vect_entite);
//				}
//				else											//Si monstre (choix aléatoire cible)
//				{
//					int cible = rand() % vect_p.size();
//					target = vect_entite[cible];
//				}
//
//                if (target.enleverVie(comp_util.getDamage()))	//Application attaque + état mort
//				{
//                    if (target.getId().substr(1, 1) == "p")		//Si personnage
//					{
//                        nb_players--;							//Personnage mort
//					}
//					else
//					{
//						nb_monsters--;							//Monstre mort
//					}
//				}
//
//				if (nb_players == 0)							//Tous personnages morts
//				{
//					//Fin de partie
//				}
//				else if (nb_monsters == 0)						//Tous monstres morts
//				{
//					//Retour carte
//				}
//			}
//		}
//	}



//	/*
//	Todo:
//	Gérer l'assignation des monstres à la carte (choix aléatoire dans le vecteur pour chaque case contenant un monstre).
//	Afficher la carte et lancer la partie.
//	Se déplacer
//	Combattre
//	Mourir
//	*/

	return 0;
}
