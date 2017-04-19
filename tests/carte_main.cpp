#include "carte.h"
#include <iostream>


using namespace std ;

int main()
{
	int size ;
	cout << "choix de la taille :" << endl;
	cin >> size;
	Carte essai(size);
	essai.affichage() ;
	essai.sauvegarde() ;
	string choix ;
	cout << "Choix de la carte : " << endl ;
	cin >> choix ;

	Carte test(100) ;
	test.chargement(choix) ;
	test.affichage() ;

}
