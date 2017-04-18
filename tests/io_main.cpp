#include <iostream>
#include "../headers/io.h"

using namespace std;
using namespace io;



int main()
{
    Bienvenue();

    cout << "Input de: ";
	char r = de();  //fait des core dump assez moches avec les autres éléments rajoutés
	cout << "Result de : " << r << endl;

//    Personnage perso("bob", 150, 5);
//    Personnage perso2("jack", 100, 7);
//
//    //Cette partie sera gérée au chargement du fichier (remplissage du vecteur à chaque ligne)
//    vector<Personnage> vect_perso;
//    vect_perso.push_back(perso);
//    vect_perso.push_back(perso2);
//
//    choix_element(vect_perso, 1);

	return 0;
}
