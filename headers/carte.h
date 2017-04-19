#include <iostream>
using namespace std ;
class Carte
{
	string nom ;
	int taille ;
	char ** plateau ;
	public:
		Carte(int taille) ;
		void affichage() ;
		void sauvegarde() ;
		bool carte_existe(string nom) ;
		void chargement (string nom_selection);
		int quel_taille(string nom);
		void suppression(string nom);
};

