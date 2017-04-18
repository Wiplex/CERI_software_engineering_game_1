#include <iostream>
#include <vector>

using namespace std;

//! Cet espace sera un espace permettant de définir un buffer custom pour les input, ainsi que de pouvoir afficher tout ce que l'on souhaite.

namespace io
{
	std::istream io_input();
	extern char de();			// Demande l'entrée utilisateur
	void Bienvenue();           //Affiche le message d'accueil (début du programme)

	//! Affichage d'objet.
    /*!
        Affiche le nom (et éventuellement la description) d'un objet.
        \param object Objet à afficher.
        \param need_desc Description ou non.
    */
    template<typename T> void afficher(T object, bool need_desc)
    {
        cout << object.get_name();                          //Affiche le nom

        if (need_desc == 1)                                 //Si une description est demandée
        {
            cout << ", \"" << object.get_desc() << "\".";   //Affiche la description
        }
    }

    //! Affichage d'un ensemble d'objets
    /*!
        Parcourt le vecteur de stockage des objets chargés, et les affiche.
        \param vect_element Vecteur d'éléments.
        \param need_desc Description ou non.
        \sa afficher()
    */
    template<typename T>void choix_element(vector<T> vect_element, bool need_desc)
    {
        typename vector<T>::iterator itv;                                   //Variable de parcours de vecteur
        int cpt = 0;                                                        //Compteur d'éléments

        for (itv = vect_element.begin(); itv != vect_element.end(); itv++)  //Parcours vecteur
        {
            cpt++;                                                          //Incrémentation compteur
            cout << cpt%10 << "- ";                                         //Numéro de l'élément (0 - 9)
            afficher(* itv, need_desc);                                     //Affichage de l'élément
            cout << "   ";
        }
    }
}

//! Classe test interactions affichage
class test
{
    string name;
    string description;

public:
    test(string nom, string desc);
    string get_name();
    string get_desc();
};
